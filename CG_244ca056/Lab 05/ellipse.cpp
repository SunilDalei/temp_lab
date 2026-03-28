#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;
float rx, ry, p1, p2, x, y;
float xc, yc;
void init(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}
void display()
{
	x = 0;
	y = ry;
	p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	while(2 * ry * ry * x <= 2 * rx * rx * y)
	{
		glVertex2f(xc+x, yc+y);
	    	glVertex2f(xc+x, yc-y);
	    	glVertex2f(xc-x, yc+y);
	    	glVertex2f(xc-x, yc-y);
		if(p1 < 0)
		{
			p1 = p1 + 2 * ry * ry * x + ry * ry;
			x++;
		}
		else
		{
			p1 = p1 + (2 * ry * ry * x) + (ry * ry) - (2 * rx * rx * y);
			x++;
			y--;
		}
	}
	
	p2 = ry * ry * ((x + 0.5) * (x + 0.5)) + (rx * rx * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
	while(y >= 0)
	{
		glVertex2f(xc+x, yc+y);
	    	glVertex2f(xc+x, yc-y);
	    	glVertex2f(xc-x, yc+y);
	    	glVertex2f(xc-x, yc-y);
		if(p2 > 0)
		{
			p2 = p2 - (2 * rx * rx * y) + (rx * rx);
			y--;
		}
		else
		{
			p2 = p2 + (2 * ry * ry * x) - (2 * rx * rx * y) + (x * rx);
			x++;
			y--;
		}
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{	cout << "Enter the value of a and b : " << endl;
	cin >> rx >> ry;
	cout << "Enter the center xc and yc " << endl;
	cin >> xc >> yc;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Ellipse");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

