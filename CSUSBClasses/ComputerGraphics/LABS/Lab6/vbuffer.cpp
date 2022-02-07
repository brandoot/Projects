
#include <stdio.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/glext.h>
#include <GL/glut.h>

//float data1 [] = { 2, 3, 1, 0, 0,  25, 5, 0, 1, 0, 12, 20, 0, 0, 1, 12, 40, 1,1,0 };
float data [] = { 2, 3, 1, 0, 0,  25, 5, 0, 1, 0, 12, 20, 0, 0, 1 };
float color [] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
unsigned int indices []  = { 0, 1, 2 };
unsigned int vbo;    //vertex buffer object
unsigned int ind;
//initialization
void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  glColor3f( 0.0f, 0.0f, 0.0f );	//set drawing color
  gluOrtho2D( 0.0, 50.0, 0.0, 50.0 );
  glGenBuffers ( 1,  &vbo );            //handle to vertex buffer object
  glGenBuffers ( 1,  &ind );
  glBindBuffer ( GL_ARRAY_BUFFER, vbo );
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, ind );
  glBufferData ( GL_ARRAY_BUFFER, sizeof ( data ), data, GL_STATIC_DRAW );
  glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( indices ), indices, GL_STATIC_DRAW );
}


void display( void )
{
  glClear( GL_COLOR_BUFFER_BIT );	//clear screen
  glEnableClientState ( GL_VERTEX_ARRAY );
  glEnableClientState ( GL_COLOR_ARRAY );
  //glLoadIdentity();
  glVertexPointer ( 2, GL_FLOAT, 5*sizeof(float), 0 );
  glColorPointer ( 3, GL_FLOAT, 5*sizeof(float), (void*) (2*sizeof(float)) );

  float substitute[] = { 5, 8 };
  glDrawArrays ( GL_TRIANGLES, 0, 3 );

  glTranslatef ( 10, 10, 0 );
  // substitute first 2 data by (5, 8) 
 glBufferSubData ( GL_ARRAY_BUFFER, 0, 2*sizeof(float), substitute );
  glDrawElements ( GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0 );  // last param=0  =>video card*/
  glDisableClientState ( GL_VERTEX_ARRAY );
  glDisableClientState ( GL_COLOR_ARRAY );
  // unbind
  glBindBuffer ( GL_ARRAY_BUFFER, 0 );
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, 0 );

  /*
  glBegin( GL_TRIANGLES );
    glVertex2f ( 2, 3 );
    glVertex2f ( 25, 5 );
    glVertex2f ( 12, 20 );
  glEnd();
  */
  glFlush();				//send all output to screen
}

void keyboard ( unsigned char key, int mousex, int mousey )
{
   switch ( key ) {
     case 27:       // escape
       exit ( -1 );
   }
   glutPostRedisplay();
}

void specialKey ( int key, int mousex, int mousey )
{
 switch ( key ) {
  case GLUT_KEY_UP:
       break;
  case GLUT_KEY_DOWN:
       break;
  case GLUT_KEY_LEFT:
   	break;
  case GLUT_KEY_RIGHT:
 	break;
  }
  glutPostRedisplay();
}

void myMouse( int button, int state, int x, int y )
{
  if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN );
  glFlush();                            //send all output to screen
}


/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, depth buffer.
 */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);	//initialize toolkit
  glutInitDisplayMode (GLUT_SINGLE| GLUT_RGB );	//set display mode
  glutInitWindowSize(800, 800);		//set window size on screen
  glutInitWindowPosition( 100, 150 ); 	//set window position on screen
  glutCreateWindow(argv[0]);		//open screen widow
  init();
  glutDisplayFunc (display);		//points to display function
  glutKeyboardFunc ( keyboard );
  glutSpecialFunc( specialKey );
  glutMouseFunc( myMouse );

  glutMainLoop();			//go into perpetual loop
  return 0;
}
