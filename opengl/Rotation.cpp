//Rotation of a Line Segement 
#include <GL/glut.h>

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // set background colour to black and opaque
	gluOrtho2D(-20.0, 20.0, 20.0, -20.0); //define cartesian co-ordinates

}
void rotate()
{

	glClear(GL_COLOR_BUFFER_BIT); //empty colour buffer
	glMatrixMode(GL_MODELVIEW); //set transformations matrix
	glLineWidth(3.0);

	glBegin(GL_LINES); //initial red line
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(5.0f, 1.5f);
	glVertex2f(9.3f, 7.2f);
	glEnd();

	glTranslatef(5.0, -2.0, 0.0); //translation vector
	glRotatef(45.0, 0.0, 1.0, 0.0); //rotation about +45 along y axis


	glBegin(GL_LINES); //rotated green line
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(5.0f, 1.5f);
	glVertex2f(9.3f, 7.2f);
	glEnd();


	glFlush(); //render output
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); //initalize glut

	glutCreateWindow("Rotation"); //set window name
	glutInitWindowSize(500, 500);//set window width and height
	glutInitWindowPosition(100, 100);//position the window to top left corner
	init(); //run init()
	glutDisplayFunc(rotate); // run rotate()
	glutMainLoop();//enter the event processing loop
}