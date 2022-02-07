//draw_main.cpp: main loop of drawing program
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//initialization
void init(void);
//does the drawing 
void display(void);

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGB display mode, single buffer.
 */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);	//initialize toolkit
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );	//set display mode: single bufferring, RGB model
  glutInitWindowSize(200, 300);		//set window size on screen
  glutInitWindowPosition( 300, 350 ); 	//set window position on screen
  glutCreateWindow(argv[0]);		//open screen window
 // glutCreateWindow( "CS 420 Draw" );		//open screen window
  init();
  glutDisplayFunc (display);		//points to display function
  glutMainLoop();			//go into perpetual loop
  return 0;
}


