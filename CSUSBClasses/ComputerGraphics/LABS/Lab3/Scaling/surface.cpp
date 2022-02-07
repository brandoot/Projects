/*
  surface.cpp
  Surface class creates a SDL surface that lets user draws upon it.
  CP and CD are the current position and current direction of the
  'drawing pen'.  By moving CP and CD, one can draw sophisticated
  2-dimensional figures and patterns including fractal-generated
  graphics. Brensham's line-drawing algorithm, where only integer
  arithmetic is involved is used to draw lines.

  @Author: T.L. Yu, April 15, 2006
*/
#include "surface.h"
#include <SDL/SDL.h>
#include <math.h>
#include <stdlib.h>

Surface:: Surface(int width, int height, char* windowTitle)
{
  // Fire up SDL. 
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        exit ( 1 );
  }
  atexit(SDL_Quit);
  // Set a video mode. Force 16-bit hicolor. 
  if (( surf = SDL_SetVideoMode(width, height, 16, 0x0)) == NULL) {
        printf("Error setting a video, 16-bit video mode: %s\n",
               SDL_GetError());
        exit( 0 );  //should use exception
  }

  CP.set( 0, 0 ); //initialize the cp to (0,0)
  color = 0xFFFF;	//default is white
} //constructor

void Surface::updateSurface()
{
  if( SDL_Flip( surf ) == -1 )
     exit( 1 );
}

SDL_Surface* Surface::getSurface()
{
  return surf;
}


//changes current point
void Surface:: moveTo( int x, int y)
{
  CP.set(x, y);
}

/*
  draws a line from current point to new point using Bresenham algorithm
  surf is the SDL_Surface of the class
*/
void Surface:: lineTo( int x1, int y1 )
{
    Uint16 *buffer;
    int drawpos;
    int xspan, yspan;
    int xinc, yinc, x0, y0;
    int sum;
    int i;

    /* If we need to lock this surface before drawing pixels, do so. */
    if (SDL_MUSTLOCK( surf )) {
	if (SDL_LockSurface(surf) < 0) {
	    printf("Error locking surface: %s\n", SDL_GetError());
	    abort();
	}
    }

    /* Get the surface's data pointer. */
    buffer = (Uint16 *)surf->pixels;

    x0 = CP.x;	y0 = CP.y;
    /* Calculate the x and y spans of the line. */
    xspan = x1-x0+1;
    yspan = y1-y0+1;
	
    /* Figure out the correct increment for the major axis.
       Account for negative spans (x1 < x0, for instance). */
    if (xspan < 0) {
	xinc = -1;
	xspan = -xspan;
    } else xinc = 1;

    if (yspan < 0) {
	yinc = -surf->pitch/2;
	yspan = -yspan;
    } else yinc = surf->pitch/2;
	
    i = 0;
    sum = 0;
	
    /* This is our current offset into the buffer. We use this
       variable so that we don't have to calculate the offset at
       each step; we simply increment this by the correct amount.

       Instead of adding 1 to the x coordinate, we add one to drawpos.
       Instead of adding 1 to the y coordinate, we add the surface's
       pitch (scanline width) to drawpos. */
    drawpos = surf->pitch/2 * y0 + x0;
	
    /* Our loop will be different depending on the
       major axis. */
    if (xspan < yspan) {

	/* Loop through each pixel along the major axis. */
	for (i = 0; i < yspan; i++) {

	    /* Draw the pixel. */
	    buffer[drawpos] = color;

	    /* Update the incremental division. */
	    sum += xspan;

	    /* If we've reached the dividend, advance
	       and reset. */
	    if (sum >= yspan) {
		drawpos += xinc;
		sum -= yspan;
	    }

	    /* Increment the drawing position. */
	    drawpos += yinc;
	}
    } else {
	/* See comments above. This code is equivalent. */
	for (i = 0; i < xspan; i++) {

	    buffer[drawpos] = color;
			
	    sum += yspan;

	    if (sum >= xspan) {
		drawpos += yinc;
		sum -= xspan;
	    }

	    drawpos += xinc;
	}
    }
    CP.set ( x1, y1 );		//set new CP position
    /* Unlock the surface. */
    SDL_UnlockSurface(surf);
}


void Surface:: clearScreen(void)
{
  SDL_PixelFormat *fmt = surf->format;
  Uint32 c =  SDL_MapRGB( fmt, 255, 255, 255 );	//white color
  SDL_FillRect( surf, NULL, c );	//fill whole screen with color
}

void Surface:: setBackgroundColor(int r, int g, int b)
{
  SDL_PixelFormat *fmt = surf->format;
  Uint32 c =  SDL_MapRGB( fmt, r, g, b );	//white color
  SDL_FillRect( surf, NULL, c );	//fill whole screen with color

  //4th variable level of transparency, may need to change 
}

void Surface:: setColor(int r, int g, int b)
{
   /* This series of bit shifts uses the information from the SDL_Format 
     structure to correctly compose a 16-bit pixel value from 8-bit
     red, green and blue data */

  SDL_PixelFormat *fmt = surf->format;

  color = (( r >> fmt->Rloss) << fmt->Rshift) +
    ((g >> fmt->Gloss) << fmt->Gshift) +
    (( b >> fmt->Bloss) << fmt->Bshift);
}

void Surface:: lineTo(Point p)
{
  lineTo ( p.x, p.y );
  CP.set(p.x, p.y);
}


void Surface:: moveTo( Point p)  //moves current point CP to point p object 
{
  CP.set ( p.x, p.y );
}


void Surface:: moveRel( int dx, int dy)
{
  CP.set(CP.x + dx, CP.y + dy);
}

//get current position
Point Surface::getCP()
{
  return CP;
}

//for turtle graphics
//since the 'origin' is at left upper corner, our direction sense is reversed
//  so clockwise and anti-clockwise are reversed
void Surface::turnTo( float angle )
{
  CD = -angle;	//set current direction
}

//since the 'origin' is at left upper corner, our direction sense is reversed
//  so clockwise and anti-clockwise are reversed
void Surface::turn( float angle )
{
  CD -= angle;	//turn anti-clockwise 
}

//move line forward by amount dist, if isVisible nonzero, line is drawn
void Surface::forward ( int dist, int isVisible )
{
  const float RadPerDeg = 0.017453393;		//radians per degree
  int x = CP.x + ( int ) ( dist * cos ( RadPerDeg * CD ));
  int y = CP.y + ( int ) ( dist * sin ( RadPerDeg * CD ));
  if ( isVisible )
    lineTo( x, y );
  else
    moveTo ( x, y );
}//forward
