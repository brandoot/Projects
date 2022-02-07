//mouse_key.cpp 
#include <GL/glut.h>
#include <stdlib.h>

#define   screenHeight  500

using namespace std;

//initialization
void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  glColor3f( 0.0f, 0.0f, 0.0f );	//set drawing color
  glPointSize( 8.0 );			//a dot is 4x4
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluOrtho2D( 0.0, 500.0, 0.0, 500.0 );
} //init

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glFlush();
}

void drawDot( int x, int y )
{
  glColor3f(0.5,0.0,0.7);
  glBegin( GL_POINTS );			
    glVertex2i( x, y );		//draw a points
  glEnd();
} //drawDot

void myMouse( int button, int state, int x, int y )
{
  if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    drawDot( x, screenHeight - y );
  glFlush();				//send all output to screen
}

void myMovedMouse(  int mouseX, int mouseY)
{
  GLint x = mouseX;
  GLint y = screenHeight - mouseY;
  GLint brushsize = 6;
  glColor3f( 1.0, 0.0, 1.0 );
  glRecti ( x, y, x + brushsize, y + brushsize );
  glFlush();
} //myMovedMouse

void myKeyboard ( unsigned char key, int mouseX, int mouseY )
{
  GLint x = mouseX;
  GLint y = screenHeight - mouseY;
  switch( key )
  {
    case 'p':
 	drawDot ( x, y );
	glFlush();
	break;
    case 'i':
	glColor3f(0.0,1.0,0.5);
	glBegin(GL_TRIANGLES);
		glVertex2i(x,y);
		glVertex2i(x-20,y+20);
		glVertex2i(x+40,y);
	glEnd();
	glFlush();
	break;
    case 'r':
        glRecti ( x, y, x + 20, y + 30 );
	glFlush();
	break;
    case 'e':
	exit ( -1 );
    default :
	break;
  }  
}


