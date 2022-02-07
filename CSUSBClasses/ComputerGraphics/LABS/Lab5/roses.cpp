#include "canvas.h"

Canvas cvs ( 800, 800, (char *) "Turtle" );
/*
void rose( int n )
{
  double K = 120, theta, x, y, f;
  double pi = 3.14159265389;
  theta = 0;
  f = K * cos ( n * theta );
  x = f * cos ( theta );
  y = f * sin ( theta );
  cvs.moveTo ( x, y );

  for ( theta = 0; theta <= 2.1 * pi; theta += 0.1 ) {
    f = K * cos ( n * theta );
    x = f * cos ( theta );
    y = f * sin ( theta );
    cvs.lineTo ( x, y );
  }
}
*/
void lspiral ( double K )
{
  cvs.setWindow ( -100, 100, -100, 100 );
  double a = 0.4, x, y, f, theta;
  const double pi = 3.14159;
  theta = 0;
  f =K * ( a * theta );
  x = f * cos ( theta );
  y = f * sin ( theta );
  cvs.moveTo ( x, y );
  for ( theta = 0; theta <= 8 * pi; theta += 0.1 ) {
    f = K* ( a * theta );
    x = f * cos ( theta );
    y = f * sin ( theta );
    cvs.lineTo ( x, y );
  }
}

void roses()
{
  cvs.setColor ( 1, 0.7, 0 );
  cvs.setViewport ( 0, 400, 0, 400 );
  lspiral (-8 );
  cvs.setColor ( 0.7, 1, 0.5 );
  cvs.setViewport ( 400, 800, 0, 400 );
  lspiral ( 3 );
  cvs.setColor ( 1, 0.5, 0.5 );
  cvs.setViewport ( 400, 800, 400, 800 );
  lspiral ( -4 );
  cvs.setColor ( 0.3, 1, 1 );
  cvs.setViewport ( 0, 400, 400, 800 );
  lspiral ( 5 ); 
  cvs.setColor ( 0.4, 0.1, 1.0 );
  cvs.setViewport ( 200, 600, 200, 600 );
  // rose ( 6 ); 
  lspiral( 7 );
}

void display(void)
{
  cvs.clearScreen();
  cvs.setWindow ( -200, 200, -200, 200 );
 
  cvs.moveTo(0.0, 0.0); //starts at center
  cvs.turnTo ( 0.0 );   //points horizontally
  glLineWidth ( 5 );
  roses();
}
  
