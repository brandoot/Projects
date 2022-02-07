#include <stdio.h>
#include <stdlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

float xc=0, yc=0;
float YRotation = 0.0;
float YTranslate = 0.0;
bool *keyStates=new bool[256];

void primsquare(void){
        glColor3f(0.7,0.7,1.0);
        glBegin(GL_POLYGON);
                glVertex2f(xc,yc);
                glVertex2f(xc+.5,yc);
                glVertex2f(xc,yc+1.0);
                glVertex2f(xc-.5,yc);
                glVertex2f(xc,yc);
        glEnd();
}
/*
void sparkle(void){
        glColor3f(0.0,0.5,0.5);
        glTranslatef(YRotation,0,0);
        primsquare();
        glTranslatef(0,YRotation,0);
        primsquare();
}
*/
void rectangle(void){
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
                glVertex2f(0,0);
                glVertex2f(2.0,0.0);
                glVertex2f(0.5,2.0);
                glVertex2f(0.5,0.0);
        glEnd();

}

void keyPressed(unsigned char key, int x, int y){
        keyStates[key]=true;
}
void keyUp(unsigned char key, int x, int y){
        keyStates[key]=false;
}

void keyOperations(void){
        if(keyStates['a']){

        }
        else{
                glLoadIdentity();
        }
}

void arrowkey(int key, int x, int y){
        switch(key){
                case GLUT_KEY_UP:
                        yc+=0.1;
                        cout<<"y:"<<y<<endl;
                        glutPostRedisplay();
                        break;
                case GLUT_KEY_DOWN:
                        yc-=0.1;
                        cout<<"y:"<<y<<endl;
                        glutPostRedisplay();
                        break;
                case GLUT_KEY_LEFT:
                        xc-=0.1;
                        cout<<"x:"<<x<<endl;
                        glutPostRedisplay();
                        break;
                case GLUT_KEY_RIGHT:
                        xc+=0.1;
                        cout<<"x:"<<x<<endl;
                        glutPostRedisplay();
                        break;
        }
}

void display(){
        //keyOperations();

        glClearColor(0.5f,0.5f,1.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

	glRotatef(-90,0,0,1);
        rectangle();

	glRotatef(-45,0,0,1);
	glColor3f(0.5,0.5,1.0);
	rectangle();

	primsquare();

        glFlush();
        glutSwapBuffers();

        YRotation+=0.5f;
}

void reshape(int width, int height){
        glViewport(0,0,(GLsizei)width,(GLsizei)height);//defines a window
        glMatrixMode(GL_PROJECTION);//switches to proj. matrix so we can manipulate how our scene is viewed
        glLoadIdentity();//clears everything
        gluPerspective(0,(GLfloat)width/(GLfloat)height,1.0,100.0);//changes perspective(FOV,aspect ratio, near plane, far plane)
        glMatrixMode(GL_MODELVIEW);//switches back so we can draw properly
}

int main(int argc, char** argv){
        glutInit(&argc, argv);//Telling program how to set up window
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );//Double buffer so we can see every frame
        glutInitWindowSize(750,600);//initial window size w x h
        glutInitWindowPosition(100,100);//where window is placed within the screen coord

        glutCreateWindow("DEMO1");//creates window and names it


        glutDisplayFunc(display);//outputs our shapes and whatnot
        glutReshapeFunc(reshape);

        //gluOrtho2D(0.0,400,0.0,400);

        glutKeyboardFunc(keyPressed);

        glutKeyboardUpFunc(keyUp);
        glutSpecialFunc(arrowkey);

        glutMainLoop();//puts program into infinite loop
}
