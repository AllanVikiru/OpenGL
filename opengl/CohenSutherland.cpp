/*
Cohen Sutherland's Line Clipping Algorithm using OpenGL
*/

//include I/O libraries and GLUT
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>


using namespace std;

//initialise window and point coordinates
int x_wmin, x_wmax, y_wmin, y_wmax;
int x_start, y_start, x_end, y_end;

//initialise region codes for points as 4- bit arrays of 0 or 1
int code_start[4] = { 0,0,0,0 };
int code_end[4] = { 0,0,0,0 };

//initialise trivially accept or reject boolean
bool rejected = false;

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // set background colour to black and opaque
	gluOrtho2D(-20.0, 20.0, 20.0, -20.0); //define cartesian co-ordinates

}

//get region code for start point 
int  getStartCode(int x, int y) {

	
	if (y > y_wmax)
	{
		code_start[0] = 1;
	}

	if (y < y_wmin)
	{
		code_start[1] = 1;
	}

	if (x > x_wmax)
	{
		code_start[2] = 1;
	}

	if (x < x_wmin)
	{
		code_start[3] = 1;
	}
	// assign 1 to position in region code array if satisifes

	int startCode = code_start[0] * 1000 + code_start[1] * 100 + code_start[2] * 10 + code_start[3];
	//convert region code array to integer for comparison 
	return startCode;
} 

//get region code for end point 
int  getEndCode(int x, int y) {


	if (y > y_wmax)
	{
		code_end[0] = 1;
	}

	if (y < y_wmin)
	{
		code_end[1] = 1;
	}

	if (x > x_wmax)
	{
		code_end[2] = 1;
	}

	if (x < x_wmin)
	{
		code_end[3] = 1;
	}
	// assign 1 to position in region code array if satisifes

	int endCode = code_start[0] * 1000 + code_start[1] * 100 + code_start[2] * 10 + code_start[3];
	//convert region code array to integer for comparison 
	return endCode;
}

//generate codes
void generateCodes() {
	getStartCode(x_start, y_start);
	getEndCode(x_end, y_end);
}

//plot line segment
void line(int x0, int y0, int x1, int y1) {

	glPointSize(3.0);
	glBegin(GL_LINES); 
	glColor3f(1.0f, 0.0f, 0.0f); //red colour
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glEnd();

}

void clip() {
	// for lines that are not candidate for clipping
	//test for trivially accepted, plot the line 
	if (getStartCode(x_start, y_start) == 0 &&
		getEndCode(x_end, y_end) == 0 &&
		rejected == false) {
		cout << "Line trivially accepted. Not a candidate for clipping" << endl;
		line(x_start, y_start, x_end, y_end);
	}
	else {
		//test for trivially rejected
		//carry out logical AND through array, if returns 1 = reject
		for (int i = 0; i < 4; i++) {
			if (code_start[i] == code_end[i] && code_start[i] == 1) 
			{
				rejected = true;
				break;
			}
		}

		if (rejected) {
			cout << "Line trivially rejected. Not a candidate for clipping" << endl;
		}
		else {
			// test for lines that are candidates for clipping
			cout << "Line trivially accepted. Candidate for clipping" << endl;
			for (int i = 0; i < 4; i++) {
				if (code_start[i] == 1) {
					switch (i)
					{
					case 0:
						y_start = y_wmax;
						break;

					case 1:
						y_start = y_wmin;
						break;

					case 2:
						x_start = x_wmax;
						break;

					case 3:
						x_start = x_wmin;
						break;
					}
				} //set start point coordinates to window coordinates
				if (code_end[i] == 1) {
					switch (i)
					{
					case 0:
						y_end = y_wmax;
						break;

					case 1:
						y_end = y_wmin;
						break;

					case 2:
						x_end = x_wmax;
						break;

					case 3:
						x_end = x_wmin;
						break;
					} //set end point coordinates to window coordinates

				}

			}
		line(x_start, y_start, x_end, y_end);
		}
	}
}
//display window and line
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 0.9f); //blue colour
	glRecti(x_wmin, y_wmin, x_wmax, y_wmax);

	glColor3f(1.0, 1.0, 1.0);
	clip();

	glFlush();
}
void main(int argc, char** argv)
{
	cout << "Enter minimum window co-ordinates: "; 
	cin >> x_wmin >> y_wmin;
	cout << "Enter maximum window co-ordinates: "; 
	cin >> x_wmax >> y_wmax;
	cout << "Enter start point co-ordinates: ";
	cin >> x_start >> y_start;
	cout << "Enter end point co-ordinates: ";
	cin >> x_end >> y_end;
	//prompts for window and point co-ordinates

	generateCodes();
	cout << "Start point code: " << code_start[0] << code_start[1] << code_start[2] << code_start[3] << endl;
	cout << "End point code: " << code_end[0] << code_end[1] << code_end[2] << code_end[3] << endl;
	//display for generated region codes

	glutInit(&argc, argv); //initalize glut
	glutCreateWindow("Cohen Sutherland Line Clipping Algorithm"); //set window name
	glutInitWindowSize(500, 500);//set window width and height
	glutInitWindowPosition(100, 100);//position window
	init();
	glutDisplayFunc(display);
	glutMainLoop();//enter the event processing loop 
}





