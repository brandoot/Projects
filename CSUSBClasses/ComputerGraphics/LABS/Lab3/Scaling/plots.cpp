/*
  plots.cpp
  Demonstrate the drawing of a line using the surface class developed
  by T.L. Yu

  @Author: T.L. Yu, April 15, 2006

*/
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "draw.h"
#include "surface.h"

using namespace std;

double f ( double x )
{
  double y = exp ( -fabs ( x ) ) * cos ( 2 * 3.1415926 * x );

  return y;
}

double g ( double x )
{
	double y = exp ( -fabs (x) ) * sin ( 2* 3.1415926 * x);

	return y;
}

double cc ( double x )
{
	double y = ( sin(x) ) / x;
	
	return y;
}

double zz ( double x )
{
	double y = exp ( x+0.5 ) /  (pow(x+0.5,2));
	
	return y;
}
int main()
{
 
  const int VWIDTH = 640;
  const int VHEIGHT = 800;

  const Point center ( VWIDTH, VHEIGHT );	//center of screen
  Surface surf( VWIDTH, VHEIGHT, (char *) "draw_line" );

  surf.clearScreen();			//clear screen
  surf.updateSurface();
  SDL_Delay ( 1000 );			//dealy one second, just for demo

  surf.setBackgroundColor ( 0xe0, 0xe0, 0xe0 );	//set background to grey

  //draw a line 
  surf.setColor ( 0xff, 0, 0 );		//using red color

  int sx, sy;
  double x, y, a, b, c, d;
  a = VWIDTH / 10.0;
  c = 0;
  b  = -VHEIGHT / 4.0;
  d  = VHEIGHT / 4.0;


  x = 0.5;                              //initial position
  y = zz ( 0.5 );
  sx = (int) ( a * x + c );
  sy = (int) ( b * y + d +900);
  surf.moveTo ( sx, sy );
cout << sx << " " << sy << endl;
  for ( x = 0.1; x < 4.5; x += 0.5 ) {
    y = zz ( x );
    sx = (int) ( a * x + c );
    sy = (int) ( b * y + d+900 );
    cout << sx << " " << sy << endl;
    surf.lineTo ( sx, sy );
  }

  surf.updateSurface();
  SDL_Delay ( 10000 );		//display 10 seconds before exit
  return 1;
}
