#include <stdio.h>
#include <stdlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

float xc=0;
float yc=0;

void init(void){
	glClearColor(1.0,1.0,1.0,1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
}

void primsquare(void){

	glBegin(GL_POLYGON);
	glColor3f(0.8,1.0,0.03);
	glVertex2f(xc,yc);
	glColor3f(1.0,0.3,0.8);
	glVertex2f(xc+0.25,yc);
	glColor3f(0.3,0.7,1.0);
	glVertex2f(xc,yc+.5);
	glColor3f(0.7,0.2,0.7);
	glVertex2f(xc-0.25,yc);
	glEnd();

	//glFlush();

}

void display(void){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glLoadIdentity();

	primsquare();

	glutPostRedisplay();
	glutSwapBuffers();
}

void reshape(int width, int height){
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(GLfloat)width/(GLfloat)height,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(100,100);

	glutCreateWindow("Well");

	init();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glClearColor(1,0.5,0.5,0);
        gluOrtho2D(0.0,400,0.0,400);


	glutMainLoop();
}
