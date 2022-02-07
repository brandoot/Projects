#include <stdio.h>
#include <stdlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

bool movingup = false;
float yLocation = 0.0f;
float yRotationAngle = 0.0f;

void init(void){
	glClearColor (0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
}

void bobjects(void){
	
	glColor3f(0.2,0.2,0.7);
	glutSolidCube(0.5);
	//glutSolidSphere(yRotationAngle,50,50);
	/*
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.5,1.0);
		glVertex2f(0.0,0.0);
		glVertex2f(1.0,-1.5);
		glVertex2f(-1.5,0.75);
	glEnd();
	*/
}

void display(void){
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(0.0f,0.0f,0.0f,1.0f);//bkgd is clear
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,-5.0f);
	glTranslatef(0.0f,yLocation,0.0f);
	glRotatef(yRotationAngle,0.4f,1.0f,0.4f);
	bobjects();
	
	glutSwapBuffers();//since we used double buffers we have to swap btwn each one

	if(movingup){
		yLocation-=0.005f;
	}
	else{
		yLocation+=0.005f;
	}

	if(yLocation<-3.0f){
		movingup=false;
	}
	else if(yLocation>3.0f){
		movingup=true;
	}
	
	yRotationAngle+=0.005f;
	if(yRotationAngle>360.0f){
		yRotationAngle-=0.005f;
	}

	//glutSwapBuffers();//since we used double buffers we have to swap btwn each one

	glDisable(GL_COLOR_MATERIAL);
}

void reshape(int width, int height){
	glViewport(0,0,(GLsizei)width,(GLsizei)height);//defines a window
	glMatrixMode(GL_PROJECTION);//switches to proj. matrix so we can manipulate how our scene is viewed
	glLoadIdentity();//clears everything
	gluPerspective(45,(GLfloat)width/(GLfloat)height,1.0,100.0);//changes perspective(FOV,aspect ratio, near plane, far plane)
	glMatrixMode(GL_MODELVIEW);//switches back so we can draw properly
}

int main(int argc, char** argv){
	glutInit(&argc, argv);//Telling program how to set up window
	glutInitDisplayMode(GLUT_DOUBLE);//Double buffer so we can see every frame
	glutInitWindowSize(500,500);//initial window size w x h
	glutInitWindowPosition(100,100);//where window is placed within the screen coord

	glutCreateWindow("Y E S");//creates window and names it

	init();

	glutDisplayFunc(display);//outputs our shapes and whatnot
	glutIdleFunc(display);
	glutReshapeFunc(reshape);//reshapes window to size we need

	glutMainLoop();//puts program into infinite loop
}
