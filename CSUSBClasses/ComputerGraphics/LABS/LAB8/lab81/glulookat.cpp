/*
 * glulookat.cpp
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

GLfloat diffuseMaterial[4] = { 0.5, 0.5, 0.5, 1.0 };

void init(void)
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glShadeModel (GL_FLAT);

   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   glColorMaterial(GL_FRONT, GL_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
}

void text18 ( char *s )
{
  char *p;

  for ( p = s; *p; p++ )
    glutBitmapCharacter ( GLUT_BITMAP_HELVETICA_18, *p );
}

void drawLine( float v0[], float v1[] )
{
   glBegin( GL_LINE );
     glVertex3fv( v0 );
     glVertex3fv( v1 );
   glEnd();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();             	// clear the matrix 
           				// viewing transformation  
   
   glLoadIdentity();
//   gluLookAt ( 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
   gluLookAt ( 3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  // gluLookAt ( 5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
   glColor3f(0, 0, 0);
   float xr = 2.2, yr = 2.2, zr = 2.2;
   glRasterPos3f (xr, 0, 0 );
   text18( "x" );
   glRasterPos3f (0,  yr, 0 );
   text18( "y" );
   glRasterPos3f (0, 0, zr );
   text18( "z" );
   float origin[3] = {0, 0, 0};
   float axes[3][3] = {{2.0, 0, 0}, {0, 2.0, 0}, {0, 0, 2.0}}; 
   for ( int i = 0; i < 3; i++ )
     drawLine ( origin, axes[i] ); 
   glColor3f (1.0, 0.0, 0.0);     //red color
   glScalef ( 2.0, 1.0, 1.0 );
  // glutSolidTeapot( 0.8 );
  // glutSolidSphere( 1, 32, 32 );
  glColor3f(0.7,0.3,0.7);
   glutWireCube (1.0);

   
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutReshapeFunc(reshape);

   glutMainLoop();
   return 0;
}
