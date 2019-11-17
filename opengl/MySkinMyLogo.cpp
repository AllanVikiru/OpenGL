#include <GL/glut.h>
#include <math.h>

void init()
{
	glClearColor(1.0f, 0.8f, 0.0f, 0.9f); // set background colour to yellow and opaque
	gluOrtho2D(-10.0, 10.0, 10.0, -10.0); //define cartesian co-ordinates

}
void MyHouse()
{
	float PI = 3.14159; //define value of PI

	//main rectangle
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glVertex2f(-2.5f, 2.5f);
	glVertex2f(-2.5f, 0.0f);
	glVertex2f(-1.5f, 0.0f);
	glVertex2f(1.5f, 0.0f);
	glVertex2f(2.5f, 0.0f);
	glVertex2f(2.5f, 2.5f);
	glVertex2f(-1.5f, -4.0f);
	glVertex2f(1.5f, -4.0f);
	glEnd();

	glFlush(); //rendering
}

void main(int argc, char**argv)
{
	glutInit(&argc, argv); //initalize glut

	glutCreateWindow("MyHouse"); //create window with given name
	glutInitWindowSize(5000, 5000);//set window width and height
	glutInitWindowPosition(100, 100);//position the window to top left corner
	init();
	glutDisplayFunc(MyHouse);
	glutMainLoop();//enter the event processing loop 
}
