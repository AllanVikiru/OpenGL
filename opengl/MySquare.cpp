/*#include <Windows.h>
#include <GL/glut.h>
#include <math.h>
void init() {
	gluOrtho2D(-0.5, 0.5, -0.5, 0.5); //define cartesian co-ordinates
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);//set background colour to black and opaque
}
void MySquare() {
	glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //red colour
glVertex2f(-0.5f, -0.5f); //-x,-y
glVertex2f(0.5f, -0.5f);//x,-y
glVertex2f(0.5f, 0.5f);//x,y
glVertex2f(-0.5f, 0.5f);//-x,y
glEnd();
glFlush();//rendering
}

int main(int argc, char**argv) {
	glutInit(&argc, argv); //initalize glut
	glutCreateWindow("MySquare"); //create window with given name
	glutInitWindowSize(320, 320);//set window width and height
	glutInitWindowPosition(50, 50);//position the window to top left corner
	init();
	glutDisplayFunc(MySquare);
	glutMainLoop();//enter the event processing loop 
}*/