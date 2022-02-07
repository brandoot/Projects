#include <stdio.h>
#include <stdlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

double x(double t){
	return cos(t);
}

double y(double t){
	return sin(t);
}

double pi = 3.14159265359;

float yRotationAngle = 0.0;

//initialize window 
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
}

//cube
void wcube(void){
	glColor3f(0.7,0.2,0.7);
	glutWireCube(1.0);
}

//creating our earth
void sphere1(void){
	glColor3f(0.0,0.2,0.7);
	glutWireSphere(0.5,50,50);
}

//creating our sun
void sphere2(void){
	glColor4f(1.0,0.6,0.6,1.0);
	glutWireSphere(1.0,50,50);
}

void display(void){
	glEnable(GL_COLOR_MATERIAL);//enable coloring

	glClearColor(1.0f,1.0f,1.0f,1.0f);//bkgd is clear
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();//clear plane of any drawings

	glTranslatef(0.0f,0.0f,-5.0f);//make sure drawings will appear

	//glTranslatef(2.0f,0.0f,0.0f);//move cube 2 units
	//glRotatef(30,0.0f,0.0f,1.0f);//rotate cube along z-axis
	//wcube();
	
	//glRotatef(30,0.0f,0.0f,1.0f);//rotate cube along z-axis
	//glTranslatef(2.0f,0.0f,0.0f);//move cube 2 units 
	//wcube();
		
/*
	GLfloat m[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	cout << m[0] << " " << m[4] << " " << m[8] << " " << m[12] << endl;
	cout << m[1] << " " << m[5] << " " << m[9] << " " << m[13] << endl;
	cout << m[2] << " " << m[6] << " " << m[10] << " " << m[14] << endl;
	cout << m[3] << " " << m[7] << " " << m[11] << " " << m[15] << endl;
*/
	glRotatef(-yRotationAngle,0.0f,-1.0f,-1.0f);
        sphere2();
	glTranslatef(x(pi),y(pi),0.0);
	glRotatef(yRotationAngle,1.0f,1.0f,0.0f);
	sphere1();
	        
      	glutSwapBuffers();//since we used double buffers, we have to swap btwn each one

	yRotationAngle+=0.5f;

	glDisable(GL_COLOR_MATERIAL);
}

//reshape window to fit our objects
void reshape(int width, int height){
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);//switches to proj. matrix so we can manipulate how our scene is viewed
	glLoadIdentity();//clears planes
	gluPerspective(45,(GLfloat)width/(GLfloat)height,1.0,100.0);//FOV,aspect ratio, near plane, far plane
	glMatrixMode(GL_MODELVIEW);//switches back so we can draw properly
}

int main(int argc, char** argv){
	glutInit(&argc,argv);//telling program how to set up window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );//set up double buffer to see every frame
	glutInitWindowSize(800,800);//initial window size w x h
	glutInitWindowPosition(100,100);//where our window will appear according to screen coord
	glutCreateWindow("LAB 8");

	init();
	
	glutDisplayFunc(display);//outputs our shapes 
	glutIdleFunc(display);
	glutReshapeFunc(reshape);//reshapes window to size we need

	glutMainLoop();//puts our program into a loop
}
