#include <GL/glut.h>
#include <math.h>



void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // set background colour to black and opaque
	gluOrtho2D(-1.5, 1.5, 1.5, -1.5); //define cartesian co-ordinates
	
}
void MyCircles()
{
	float PI = 3.14159; //define value of PI
	// draw first circle
	float x, y;
	glColor3f(1.0f,0.0f,0.0f); //define colour to red

	for (float theta = 0; theta <= 2 * PI; theta += 0.01)
	{
		glBegin(GL_POINTS);
		glVertex2f((0.3) * cos(theta), (0.3) * sin(theta));
		glEnd();
	}

	//draw second circle 
	float a, b;
	glColor3f(0.0f, 1.0f, 0.0f);

	for (float theta = 0; theta <= 2 * PI; theta += 0.01)
	{
		glBegin(GL_POINTS);
		glVertex2f((0.3) * cos(theta) + 0.3, (0.3) * sin(theta) + 0.2);
		glEnd();

	}

	//draw third circle
	float c, d;
	glColor3f(0.0f, 0.0f, 1.0f);
	for (float theta = 0; theta <= 2 * PI; theta += 0.01)
	{
		glBegin(GL_POINTS);
		glVertex2f((0.3) * cos(theta) + 0.3, (0.3) * sin(theta) - 0.3);
		glEnd();

	}

	glFlush(); //rendering
}
void main(int argc, char**argv)
{
	glutInit(&argc, argv); //initalize glut

	glutCreateWindow("MyCircles"); //create window with given name
	glutInitWindowSize(600, 600);//set window width and height
	glutInitWindowPosition(50, 50);//position the window to top left corner
	init();
	glutDisplayFunc(MyCircles);
	glutMainLoop();//enter the event processing loop 
}

