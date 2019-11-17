#include <GL/glut.h>
#include <math.h>

void init()
{
	glClearColor(1.0f, 0.8f, 0.0f, 0.9f); // set background colour to yellow and opaque
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0); //define cartesian co-ordinates
}
void MyHouse()
{
	float PI = 3.14159; //define value of PI

	//main house
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glVertex2f(-3.5f, 0.0f);
	glVertex2f(3.5f, 0.0f);
	glVertex2f(3.5f, -1.0f);
	glVertex2f(3.0f, -1.0f);
	glVertex2f(3.0f, -4.5f);
	glVertex2f(-3.0f, -4.5f);
	glVertex2f(-3.0f, -1.0f);
	glVertex2f(-3.5f, -1.0f);
	glEnd();

	//door
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //white colour
	glVertex2f(-0.5f, -4.5f);
	glVertex2f(0.5f, -4.5f);
	glVertex2f(0.5f, -1.5f);
	glVertex2f(-0.5f, -1.5f);
	glEnd();

	//left window
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f); //yellow colour
	glVertex2f(-2.5f, -2.0f);
	glVertex2f(-1.5f, -2.0f);
	glVertex2f(-1.5f, -3.0f);
	glVertex2f(-2.5f, -3.0f);
	glEnd();

	//left horizontal window frame
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glVertex2f(-2.5f, -2.5f);
	glVertex2f(-1.5f, -2.5f);
	glEnd();

	//left vertical window frame
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glVertex2f(-2.0f, -2.0f);
	glVertex2f(-2.0f, -3.0f);
	glEnd();

	//right window
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f); //yellow colour
	glVertex2f(2.5f, -2.0f);
	glVertex2f(1.5f, -2.0f);
	glVertex2f(1.5f, -3.0f);
	glVertex2f(2.5f, -3.0f);
	glEnd();

	//right horizontal window frame
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glVertex2f(2.5f, -2.5f);
	glVertex2f(1.5f, -2.5f);
	glEnd();

	//right vertical window frame
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glVertex2f(2.0f, -2.0f);
	glVertex2f(2.0f, -3.0f);
	glEnd();

	//arc roof
	
	glBegin(GL_POINTS); 
	glColor3f(0.0f, 0.0f, 0.9f); 
	for (int i = 1; i < 1000; i++) {
		glVertex3f(cos(1 * PI * i / 1000.0), sin(1 * PI * i / 1000.0), 0); 
	}
	glEnd();

	glFlush(); //rendering

}

void main(int argc, char**argv)
{

	glutInit(&argc, argv); //initalize glut
	glutCreateWindow("MyHouse"); //create window with given name
	glutInitWindowSize(500, 500);//set window width and height
	glutInitWindowPosition(50, 50);//position the window to top left corner
	init();
	glutDisplayFunc(MyHouse);
	glutMainLoop();//enter the event processing loop 
}
