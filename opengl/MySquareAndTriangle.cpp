#include <Windows.h>
#include <GL/glut.h>
#include <math.h>
void init() {
	gluOrtho2D(-1.5, 1.5, -1.5, 1.5); //define cartesian co-ordinates
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);//set background colour to black and opaque
}
void MySquareandTriangle() {

	glPointSize(3);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); //red colour
	glVertex2f(-0.5f, -0.5f); //-x,-y
	glVertex2f(0.5f, -0.5f);//x,-y
	glVertex2f(0.5f, 0.5f);//x,y
	glVertex2f(-0.5f, 0.5f);//-x,y
	glEnd();
	

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.5f, -0.25f);
	glVertex2f(-0.5f, -0.25f);
	glVertex2f(0.0f, 0.75f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.25f, 0.0f);
	glVertex2f(0.0f, 0.25f);
	glVertex2f(-0.25f, 0.0f);
	
	glEnd();
	glFlush();//rendering
}

int main(int argc, char**argv) {
	glutInit(&argc, argv); //initalize glut
	glutCreateWindow("MySquareandTriangle"); //create window with given name
	glutInitWindowSize(320, 320);//set window width and height
	glutInitWindowPosition(50, 50);//position the window to top left corner
	init();
	glutDisplayFunc(MySquareandTriangle);
	glutMainLoop();//enter the event processing loop 
}
