/*
Midpoint Circle Algorithm using OpenGL
	 by Joan Ndung'u - 100388, Allan Vikiru - 098587 and Kelsey Makale - 100052


#include <stdio.h> // import standard input/output header
#include <iostream> // import I/0 library
#include <GL/glut.h> // import GL library

using namespace std; 

int xk, yk, r; // initialise values of x(k), y(k) and radius r

void init(void){
	glClear(GL_COLOR_BUFFER_BIT); //empty colour buffer
	glClearColor(0.0, 0.0, 0.0, 1.0); //define background colour to black and opaque
	gluOrtho2D(-100, 100, 100, -100); //define Cartesian coordinates
}

void points(int x, int y) { // function for drawing points on the circle
	glPointSize(2); //define point size
	glBegin(GL_POINTS); //declare output primitive
	glVertex2i(x + xk, y+yk); // define dimensions and data types of vertex
	glEnd();//declare end of defining output primitve
}

void circle(){
	int x = 0;
	int y = r; // initialise the first point to plot on circumference centered at (0,0) to (0,r)

	float p = 1 - r; //initialise decision parameter

	points(x, y); //begin test for plotting circle points

	while (y >= x){ // as the value of y approaches x
		if (p < 0){
			x++;				//if p(k) < 0 plot (x(k + 1), y(k)) 
			p += 2 * x + 1; // and  p(k+1)= p(k) + 2x(k) +3    
		}
		else{
			y--;
			x++;		// if p(k) > = 0 plot  plot (x(k+1), y(k-1))
			p += 2 * (x - y) + 1; // and p(k+1) = p(k) + 2x(k) - 2y(k) + 5
		}

		points(x, y);
		points(x, -y);
		points(-x, y);
		points(-x, -y);
		points(y, x);
		points(-y, x);
		points(y, -x);
		points(-y, -x); //plotting points along the circle octants
	}
}

void myCircle() { //function for displaying the circle
	circle(); //parse the co-ordinates through the function
	glFlush(); //render output
}

void main(int argc, char** argv)
{
	cout << "The co-ordincates of the centre of the circle are set to (0,0)" << endl;
	cout << "Enter x co-ordinate   : "; 
	cin >> xk;
	cout << "Enter y co-ordinate : "; 
	cin >> yk;
	cout << "Enter radius of circle : "; 
	cin >> r; 
	//I/O prompts to enter x (k) , y(k) and radius r

	glutInit(&argc, argv); // initialize glut
	glutInitWindowSize(300, 300); // set window height and length to 300 by 300
	glutInitWindowPosition(250, 250); // set position of window on screen to 250x250
	glutCreateWindow("Midpoint Circle"); // create window with name - "Midpoint Circle"
	init(); // run function init()
	glutDisplayFunc(myCircle); // run function myCircle
	glutMainLoop(); // enter event processing loop

}
*/