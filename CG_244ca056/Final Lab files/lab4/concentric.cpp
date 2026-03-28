#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

float r1, r2, xc, yc;

void init()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    
    float p = 1 - r1, x = 0, y = r1;

    glBegin(GL_POINTS);
    	while(x<=y) {
    		glVertex2i(xc+x, yc+y);
    		glVertex2i(xc+x, yc-y);
    		glVertex2i(xc-x, yc+y);
  	    	glVertex2i(xc-x,yc-y);    	
  	    	glVertex2i(xc+y, yc+x);
  	    	glVertex2i(xc-y, yc+x);
  	    	glVertex2i(xc+y, yc-x);
  	    	glVertex2i(xc-y, yc-x);
  	    	if(p<0) {
  	    		p = p + 2 * x + 3;
  	    		x++;
  	    	}
  	    	else {
  	    		p = p + 2 * (x-y) + 1;
  	    		x++;
  	    		y--;
  	    	}
	}
	p = 1 - r2, x = 0, y = r2;
	    while(x<=y) {
    		glVertex2i(xc+x, yc+y);
    		glVertex2i(xc+x, yc-y);
    		glVertex2i(xc-x, yc+y);
  	    	glVertex2i(xc-x,yc-y);    	
  	    	glVertex2i(xc+y, yc+x);
  	    	glVertex2i(xc-y, yc+x);
  	    	glVertex2i(xc+y, yc-x);
  	    	glVertex2i(xc-y, yc-x);
  	    	if(p<0) {
  	    		p = p + 2 * x + 3;
  	    		x++;
  	    	}
  	    	else {
  	    		p = p + 2 * (x-y) + 1;
  	    		x++;
  	    		y--;
  	    	}
	}
    glEnd();
    glFlush();
}



int main(int argc, char ** argv){
	cout << "Enter the radius of both the circles: ";
	cin >> r1 >> r2;
	cout << "Enter the coordinates of center of the circle: ";
	cin >> xc >> yc;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Mid point Circle Algorithm");		
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
