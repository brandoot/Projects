#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

void init(void);
void display (void);

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900,900);
	glutInitWindowPosition(200,200);
	glutCreateWindow(" First Window :)) ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
