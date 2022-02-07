//draw.cpp : demo program for drawing 3 dots, two lines, ploylines, rectangles
#include <GL/glut.h>

using namespace std;

//initialization
void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  glColor3f( 0.0f, 1.0f, 0.0f );	//set drawing color
  glPointSize( 8.0 );			//a dot is 4x4
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();			//replace current matrix with identity matrix
  gluOrtho2D( 0.0, 550.0, 0.0, 550.0 );
}

void display( void )
{
  glViewport(150,200,250,100);
  glClear( GL_COLOR_BUFFER_BIT );	//clear screen
  /*
  glColor3f ( 0.0, 1.0, 0.0 );
  glBegin( GL_POINTS );			//draw points
    glVertex2i( 100, 50 );		//draw a point
    glVertex2i( 100, 150 );		//draw a point
    glVertex2i( 200, 200 );		//draw a point
  glEnd();
  
  glColor3f ( 1.0, 0.0, 0.0 );
  glBegin( GL_LINES );			//draw lines
    glVertex2i( 20, 20 );		//horizontal line
    glVertex2i( 400, 20 );
    glVertex2i( 20, 10 );		//vertical line
    glVertex2i( 20, 400 );
  glEnd();
*/
  glColor3f ( 0.0, 1.0, 0.3 );		//changed color to green
  glBegin( GL_LINE_STRIP );		//draw polyline
    glVertex2i( 45, 45 );
    glVertex2i( 145, 250 );
    glVertex2i( 250, 45 );
    glVertex2i( 45, 45 );
  glEnd();
/*
  glColor3f( 0.6, 0.6, 0.6 );		//bright grey
  glRecti( 400, 400, 450, 480 );
  */
  glColor3f( 0.6, 1.0, 0.0 );		//red changed color to brightgreen
  glRecti( 400, 450, 280, 290 );
  glFlush();				//send all output to screen
}
