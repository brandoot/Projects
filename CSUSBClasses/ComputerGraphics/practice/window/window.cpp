#include <GL/glut.h>

using namespace std;

void init(void){
	glClearColor(1.0,1.0,1.0,0.0);	//white bkgd
	glColor3f(0.0f,0.0f,1.0f);	//set drawing color
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();		//replace current drawing
	gluOrtho2D(0.0,600.0,0.0,600.0);
}

void display (void){
	glViewport(150,200,250,100);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.6,0.0);
	glBegin(GL_LINE_STRIP);
		glVertex2i(45,45);
		glVertex2i(90,90);
	glEnd();
	glFlush();
}
