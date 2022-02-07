/*
  draw_demo.cpp
  Demonstrate the use of turtle grapics using the surface class developed
  by T.L. Yu

  @Author: T.L. Yu, April 15, 2006

*/
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "draw.h"
#include "surface.h"

//draw a hook
void draw_hook ( Surface &surf, int L )
{
  surf.forward ( L, 1 );
  surf.turn( 90 );
  surf.forward ( L/5, 1 );
  surf.turn ( 90 );
  surf.forward ( L/3, 1 );
}

//draw a star pattern
void draw_star( Surface &surf, int L )
{
  for ( int i = 0; i < 5; ++i ) {
    surf.forward( L, 1 );
    surf.turn( 144 );
  }
}

//draw an n-sided regular polygon
void draw_polygon ( Surface &surf, int n,  int radius, float rotAngle )
{
  if ( n < 3 ) return;				//bad number of sides
  int cx = surf.getCP().x;
  int cy = surf.getCP().y;
  double angle = rotAngle * 3.14159265 / 180;	//initial angle
  double angleInc = 2 * 3.14159265 / n;		//angle increment
  surf.moveTo ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  for ( int k = 0; k < n; k++ ) {		//repeat n times
    angle += angleInc;
    surf.lineTo ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  }
} //draw_polygon

//draw more polygones
void drawathing (Surface &surf, int n, int radius, float rotAngle,int a){

for(int i=0;i<a;i++){

	draw_polygon(surf, n, radius, rotAngle);
	surf.turn(50);;
}
}


void draw_arc (Surface &surf, int n, int radius, float rotAngle)
{
	if(n<3) return;
	int cx = surf.getCP().x;
	int cy = surf.getCP().y;
	double angle = rotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / n;
	surf.moveTo( (int) (radius*cos(angle) + cx),
		(int)(radius*sin(angle) +cy));
	for (int k = 0; k < n/2; k++) {
		angle += angleInc;
		surf.lineTo((int)(radius*cos(angle)+cx),
			(int)(radius*sin(angle)+cy));
	}
}

//draw complex shape
void draw_smth (Surface &surf,int L,double x)
{	
	for(double i=0;i<x;i+=0.5){
		surf.forward(L,1);
		surf.turn(60);
		surf.forward(L/3,1);
		surf.turn(45);
		surf.forward(L/5,1);
		surf.turn(95);
	}	
}

//draw another shape
void draw_a_s (Surface &surf, int n, int radius, float rotAngle)
{
        if(n<3) return;
        int cx = surf.getCP().x;
        int cy = surf.getCP().y;
        double angle = rotAngle * 3.14159265 / 48;
        double angleInc = 4 * 3.14159265 / n;
        surf.moveTo( (int) (radius*cos(angle) + cx),
                (int)(radius*sin(angle) +cy));
        for (int k = 0; k < n; k++) {
                angle += angleInc;
                surf.lineTo((int)(radius*cos(angle)+cx),
                        (int)(radius*sin(angle)+cy));
        }
}

//draw more shapes
void draw_m_s (Surface &surf, double n, int radius, float rotAngle)
{
        if(n<3) return;
        int cx = surf.getCP().x;
        int cy = surf.getCP().y;
        double angle = rotAngle * 3.14159265 / 57;
        double angleInc = 0.5 * 3.14159265 / n;
        surf.moveTo( (int) (radius*cos(angle) + cx),
                (int)(radius*sin(angle) +cy));
        for (double k = 0; k < n; k+=.5) {
                angle += angleInc;
                surf.lineTo((int)(radius*cos(angle)+cx),
                        (int)(radius*sin(angle)+cy));
        }
	
	for(int i=n;i!=0;i--){
	surf.forward(radius,2);
	surf.turn(25);
	surf.forward(radius,2);
	surf.turn(5*n);
	surf.forward(radius,2);
	surf.turn(n*10);
	}

}



//draw rosette with N-sided polygon
void rosette (Surface &surf,  int N, int radius )
{
  if ( N < 3 ) return;
  Point pt[N+1];

  int cx = surf.getCP().x;
  int cy = surf.getCP().y;
  double angle = 0;				//initial angle
  double angleInc = 2 * 3.14159265 / N;		//angle increment
  pt[0] = Point ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  for ( int k = 1; k < N; k++ ) {		//repeat n times
    angle += angleInc;
    pt[k] = Point ( ( int) (radius * cos( angle ) + cx), 
		 ( int ) ( radius * sin ( angle ) + cy ) );
  }
  for ( int i = 0; i < N - 1; i++ ) {
    for ( int j = i + 1; j < N; j++ ) {
    	surf.moveTo ( pt[i] );	//connect all vertices
    	surf.lineTo ( pt[j] );
    }
  }
} //rosette
 
int main()
{
 
#ifndef ARM
    const int VWIDTH = 640;
    const int VHEIGHT = 480;
#else
    const int VWIDTH = 320;
    const int VHEIGHT = 240;
#endif

  const Point center ( VWIDTH/2, VHEIGHT/2 );	//center of screen
  Surface surf( VWIDTH, VHEIGHT, (char *) "Draw_demo" );

  surf.clearScreen();			//clear screen
  surf.updateSurface();
  SDL_Delay ( 1000 );			//dealy one second, just for demo

  surf.setBackgroundColor ( 0xe0, 0xe0, 0xe0 );	//set background to grey
/*
  //draw a hook
  surf.setColor ( 0xff, 0, 0 );		//using red color
  surf.moveTo ( center );		//move to center of screen
  surf.turnTo ( 0 );			//points horizontally
  draw_hook ( surf, 60 );

  //draw a star
  surf.setColor ( 0, 0xff, 0 );		//using green color
  surf.moveTo ( center.x + 90, center.y  );
  surf.turnTo ( 0 );			//points horizontally
  draw_star ( surf, 50 );

  //draw an octagon
  surf.setColor ( 0, 0xf3, 0xf1 );	//using blue color
  surf.moveTo ( center.x, center.y - 90  );
  draw_polygon ( surf, 8, 40, 0 );	//draw an octagon
  draw_polygon ( surf, 8, 40, 0 );	//draw an octagon
  draw_polygon ( surf, 8, 40, 0 );	

  //draw an 8-sided rosette
  surf.setColor ( 0, 0.6, 0.5 );	//using black color
  surf.moveTo ( center.x - 90, center.y + 90  );
  rosette ( surf, 8, 50 );

  //draw a circle
  surf.setColor(0xf2,0,0xf5);
  surf.moveTo (center.x,center.y-90);
  draw_polygon(surf,1000,70,20);

  //draw a hexagon
  surf.setColor(0,0xf2,0xf1);
  surf.moveTo (center.x-105,center.y-90);
  draw_polygon (surf,6,35,80);

  //draw arc
  surf.setColor(0xf4,0x1,0);
  surf.moveTo (center.x+105,center.y-300);
  draw_arc (surf,1000,50,0);

  //draw smth
  surf.setColor(0xA,0x5,0xf4);
  surf.moveTo(center.x-5,center.y+50);
  draw_smth(surf,100,5);
	
  //draw another shape
  surf.setColor(0xF,0xF,0XF);
  surf.moveTo(center.x-100,center.y+90);
  draw_a_s(surf,7,150,0);

  //draw more shapes
  surf.setColor(0x4,0,0xf);
  surf.moveTo(center.x,center.y);
  draw_m_s(surf,20,50,0);


for(int i=0;i<4;i++){
  surf.setColor(0,0,0xFF-i);
  surf.moveTo(center.x,center.y);
  draw_m_s(surf,75,40,0);
}

  surf.setColor(0xff,0,0xff);
  surf.moveTo(center.x,center.y);
  draw_star(surf,100);

  surf.setColor(0xff,0,0);
  surf.moveTo(center.x+52,center.y-15);
  draw_polygon(surf,500,50,0);

  surf.setColor(0,0xff,0);
  surf.moveTo(center.x-60,center.y+15);
  draw_polygon(surf,6,50,0);
*/
  surf.setColor(0xFF,0x08,0xFF);
  surf.moveTo(center.x+100,center.y-50);
  draw_polygon(surf,6,50,0);

  surf.setColor(0xf,0,0xF);
  surf.moveTo(center.x-100,center.y+50);
  draw_polygon(surf,1000,50,0);

  surf.setColor(0xFF,0,0x08);
  surf.moveTo(center.x,center.y);
  draw_arc(surf,1000,50,0);

  surf.updateSurface();
  SDL_Delay ( 15000 );		//display 5 seconds before exit
  return 1;
}
