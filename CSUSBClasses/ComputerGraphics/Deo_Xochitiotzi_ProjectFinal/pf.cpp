/*Brandon Deo
 * Armando X.
 * Final Project
 * PROF YU
 * cse 420
 * to compile, do:
 * g++ pf.cpp -o pf -lGL -lGLU -lglut
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

bool movingUp=false;
float xr = 0, yr = 0;
float yrot=0.0;
float i=1.0,j=0.5,k=0.25;
float q=128;
float yloc = 0.0f;
GLfloat dMAT[]={0.0,0.0,1.0};
GLfloat sMAT[]={0.6,0.0,0.8};
GLfloat eMAT[]={0.8,0.8,1.0};
GLfloat sLIG[]={1.0,1.0,1.0};
GLfloat aLIG[]={k,i,j};
GLfloat dLIG[]={1.0,1.0,1.0};
GLfloat bMAT[]={0.0,0.0,0.0};
GLfloat mSHI[]={q};
GLfloat density = 0.7;
GLfloat fogColor[4]={i,j,k,1.0};

void init(void){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_BLEND);
	glEnable(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE,GL_LINEAR);
        glFogfv(GL_FOG_COLOR,fogColor);
        glFogf(GL_FOG_DENSITY,density);
        glHint(GL_FOG_HINT,GL_DONT_CARE);

}

void light(void){
	glLightfv(GL_LIGHT0,GL_SPECULAR,sLIG);
	glLightfv(GL_LIGHT0,GL_AMBIENT,aLIG);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,dLIG);
}

void moon(void){
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_DIFFUSE,dMAT);
	glMaterialfv(GL_FRONT,GL_SPECULAR,sMAT);
	glMaterialfv(GL_FRONT,GL_EMISSION,eMAT);
	glMaterialfv(GL_FRONT,GL_SHININESS,mSHI);
	glRotatef(yrot,1,1,0);
	glutSolidSphere(0.5,50,50);
	glPopMatrix();
}

void river(void){

	glPushMatrix();
	glRotatef(135,1,0,0);
	glTranslatef(0,0.45,0);
	glScalef(1,2,2);	
	glColor3f(0.1,0.1,1.0);
	glutSolidCube(0.35);
	glPopMatrix();
}

void riverbed(void){
	
	glPushMatrix();
	glScalef(2.0,1,3.0);
	glColor3f(0.0,1.0,0.0);
	glutSolidCube(0.5);
	glPopMatrix();
}

void sparkles(void){
	glPushMatrix();
	glColor3f(1.0,1.0,0.0);
	glRotatef(45,0,0,1);
	glutSolidCube(0.1);
	glPopMatrix();
}

void display1(void){
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	light();

	glPushMatrix();	
	glTranslatef(yloc,yloc,0.0f);
	sparkles();
	glTranslatef(yloc,yloc,0.0f);
        sparkles();
	glTranslatef(0.0f,yloc,yloc);
        sparkles();
	glTranslatef(yloc,yloc,0.0f);
        sparkles();
 	glTranslatef(0.0f,0.0f,yloc);
        sparkles();
	glTranslatef(0.0f,0.0,yloc);
        sparkles();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75,0,1);
	glRotatef(90,0,0,1);
	glRotatef(45,1,1,0);
	glScalef(1.5,1,1);
	riverbed();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(+0.75,0,1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,1,0);
	glScalef(1.5,1,1);
        riverbed();
        glPopMatrix();

	
	glPushMatrix();
	glScalef(2,2,2);
	river();
	glPopMatrix();
	moon();	

	glutSwapBuffers();

	if (movingUp) // If we are moving up  
	yloc -= 0.005f; // Move up along our yLocation  
	else  // Otherwise  
	yloc += 0.005f; // Move down along our yLocation
	
	if (yloc < -1.0f) // If we have gone up too far  
	movingUp = false; // Reverse our direction so we are moving down  
	else if (yloc > 1.0f) // Else if we have gone down too far  
	movingUp = true; 

	yrot++;
}

void keyOps(unsigned char key, int x, int y){
        if(key=='q'){
                glFogi(GL_FOG_MODE,GL_LINEAR);
        }
        if(key=='w'){
                glFogi(GL_FOG_MODE,GL_EXP);
        }
        if(key=='e'){
                glFogi(GL_FOG_MODE,GL_EXP2);
        }
     	if(key=='a'){
                i+=0.1;
                if(i>1.0)
                        i-=0.9;
		fogColor[0]=i;
       	        glFogfv(GL_FOG_COLOR,fogColor);
		glLightfv(GL_LIGHT0,GL_AMBIENT,aLIG);
	}
	if(key=='s'){
                j+=0.2;
                if(j>1.0)
                        j-=0.9;
		fogColor[1]=j;
		glFogfv(GL_FOG_COLOR,fogColor);
		glLightfv(GL_LIGHT0,GL_AMBIENT,aLIG);
	}
	if(key=='d'){
                k+=0.05;
                if(k>1.0)
                        k-=0.9;
		fogColor[2]=k;
	        glFogfv(GL_FOG_COLOR,fogColor);
		glLightfv(GL_LIGHT0,GL_AMBIENT,aLIG);
	}
	if(key=='r'){
		if(q==0)
			q+=128;
		else
			q--;
	}
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(750,750);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Project");

	init();

	glutDisplayFunc(display1);
	glutIdleFunc(display1);
	glutKeyboardFunc(keyOps);
	glutMainLoop();
	return 0;
}
