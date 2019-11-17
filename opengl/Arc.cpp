#include <Windows.h>
#include <GL/glut.h>
#include <math.h>


void init() {
	gluOrtho2D(-2.0, 2.0, 2.0, -2.0); //define cartesian co-ordinates
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//set background colour to white and opaque
	
}
void MyArc(){
	float PI = 3.14159; //define value of PI
		glBegin(GL_POINTS); //declare output primitive
		glColor3f(0.0f, 0.0f, 0.0f); // set shape colour to black
		for (int i = 0; i < 1000; i++) {
			glVertex3f(cos(1 * PI * i / 1000.0), sin(1 * PI * i / 1000.0), 0); //define arc vertices
		}
		glEnd();
		glFlush(); //Render now



	}
int main(int argc, char**argv) {
	glutInit(&argc, argv); //initalize glut
	glutCreateWindow("MyArc"); //create window with given name
	glutInitWindowSize(320, 320);//set window width and height
	glutInitWindowPosition(50, 50);//position the window to top left corner
	init();
	glutDisplayFunc(MyArc);
	glutMainLoop();//enter the event processing loop 
}
