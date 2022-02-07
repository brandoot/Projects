#include <stdio.h>
#include <stdlib.h>
#include <GL/glx.h>    
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

//initialize pos of char


float xc = 0, yc = 0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.3, 0.5);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(xc+100,yc+100);
	glVertex2f(xc-50,yc-50);
	glVertex2f(xc-25,yc-25);
	glVertex2f(xc+60,yc+60);
	glVertex2f(xc+30,yc-40);
	glEnd();

	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void arrowkey(int key,int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			yc++;
			cout<<y<<endl;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			yc--;
			cout<<y<<endl;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			xc--;
			cout<<x<<endl;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			xc++;
			cout<<x<<endl;
			glutPostRedisplay();
			break;
	}
}

int main (int argc, char** argv){
	printf("Use arrow keys");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(600,50);
	glutCreateWindow("demo");

	glutDisplayFunc(display);

	glClearColor(1,0.5,0.5,0);
	gluOrtho2D(0.0,400,0.0,400);
	glutSpecialFunc(arrowkey);

	glutMainLoop();

	return 0;
}
