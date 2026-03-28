#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

float x1, x2, y_1, y2;
void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display()
{
	float dx = x2 - x1;
	float dy = y2 - y_1;
	float x = x1, y = y_1;
	float m = dy / dx;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	cout << "Points rendered..... " << endl;
	while(x <= x2 && y <= y2)
	{
		glVertex2i(x, y);
		if(m <= 1)
		{
			x = x + 1;
			y = y + m;
		}
		else
		{
			
			y = y + 1;
			x = (1 + m * x) / m;
		}
	}
	glEnd();
	glFlush();
	
}


int main(int argc, char ** argv){
	cout << "Enter the co-ordinates of the starting point : " << endl;
	cin >> x1 >> y_1;
	cout << "Enter the co-ordinates of the ending point :  " << endl;
	cin >> x2 >> y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Program OutPut");		
	init();
	glutDisplayFunc(display);
	glutMainLoop();



	return 0;
}
