/*

Bresenham's Line Algorithm using OpenGL
	 by Joan Ndung'u - 100388, Allan Vikiru - 098587 and Kelsey Makale - 100052



#include <gl/glut.h> //import GL library
#include <stdio.h> //import standard input/output header

int x1, y1, x2, y2; // initialize x and y co-ordinates for start and end points

void init() {
	glClear(GL_COLOR_BUFFER_BIT); //empty colour buffer
	glClearColor(0.0, 0.0, 0.0, 1.0); //define background colour to black and opaque
	gluOrtho2D(0, 100, 0, 100); //define Cartesian coordinates

}
void points(int x, int y) { // function for drawing points on the line
	glPointSize(2); //define point size
	glBegin(GL_POINTS); //declare output primitive
	glVertex2i(x, y); // define dimensions and data types of vertex
	glEnd();//declare end of defining output primitve
}

void line(int x1, int x2, int y1, int y2) { // function for computing points
	int dx, dy, i, p; // declare values of change in x and y, iterator value and p value
	int incx, incy; //declare incremental values of x, y along the line
	int inc1, inc2; // declare incremental values of p(k+1) depending on two conditions: p(k) >= 0 or p(k) < 0
	int x, y; //declare values of coordinates of points(x,y) along the lines

	dx = x2 - x1; // find change in x: dx
	dy = y2 - y1; // find change in y: dy

	if (dx < 0) dx = -dx; //set dx to -dx if change in x is less than 0 
	if (dy < 0) dy = -dy;// set dy to -dy of change in y is less than 0

	incx = 1; // set incremental value of x to 1

	if (x2 < x1)// if end point x is less than start point x
		incx = -1; // set incremental value of x to -1
	incy = 1; // set incremental value of y to 1

	if (y2 < y1) // if end point y is less than start point y
		incy = -1; // set incremental value of y to -1

	x = x1;  //set point x to start point x
	y = y1; // set point y to start point y
	

	if (dx > dy) { //if change in x is greater than change in y i.e. gradient m is greater than 1
		points(x, y); // plot point with co-ordinates x,y
		p = (2 * dy) - (2 * dx); // value of  initial p(k)

		inc1 = (2 * dy) - (2 * dx);
		inc2 = 2 * dy;		//set incremental values of p(k)

		for (i = 0; i < dx; i++) { //iterate for every value of k until it attains the value of change in x
			if (p >= 0) {
				y += incy;
				p += inc1; // if p(k) is greater than or equal to 0 add 1 to y-co-rdinate and 2(dy-dx) to p(k)
			}
			else
				x += incx;
			p += inc2; // if p(k) is less than 0 add 1 to x-co-rdinate and 2(dy) to p(k)

			points(x, y); //plot  new point (x,y)
		}
	}

	else { // if change in y is greater than x i.e. gradient m is less than 1
		points(x, y); // plot point with co-ordinates x, y
		p = (2 * dx) - (2 * dy); //value of initial p(k)

		inc1 = (2 * dx) - (2 * dy);
		inc2 = 2 * dx;  //set incremental values of p(k)

		for (i = 0; i < dy; i++) { //iterate for every value of k until it attains value of change in y
			if (p >= 0) {
				x += incx;
				p += inc1; // if p(k) is greater than or equal to 0 add 1 to x-co-ordinate and 2(dx-dy) to p(k)
			}
			else
				y += incy;
			p += inc2; // if p(k) is less than or equal to 0 add 1 to y-co-ordinate and 2(dx) to p(k)

			points(x, y); // plot new point (x,y)

		}
	}
}

void myLine() { // function for displaying line
	line(x1, x2, y1, y2); // parse the co-ordinates through the function
	glFlush(); // render output
}

int main(int argc, char** argv) {
	printf("Enter x1, y1 (start point)\n");  //prompt to input start point
	scanf_s("%d %d", &x1, &y1); //input for start point
	printf("Enter x2, y2 (end point)\n"); //prompt to input end point
	scanf_s("%d %d", &x2, &y2); // input for end point

	glutInit(&argc, argv); // initialize glut
	glutInitWindowSize(300, 300); // set window height and length to 300 by 300
	glutInitWindowPosition(250, 250); // set position of window on screen to 250x250
	glutCreateWindow("Bresenham's Line"); // create window with name - "Bresenham's Line"
	init(); // run function init()
	glutDisplayFunc(myLine); // run function myLine
	glutMainLoop(); // enter event processing loop

}
*/