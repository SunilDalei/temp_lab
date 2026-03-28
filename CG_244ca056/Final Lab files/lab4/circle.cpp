#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

float r, p, x, y;
float xc=100, yc=100;
void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(1.0);
    
    p = 1 - r, x = 0, y = r;

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
    glEnd();
    glFlush();

}



int main(int argc, char ** argv){
	cout << "Enter the radius of circle: ";
	cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Mid point Circle Algorithm");		
	init();
	glutDisplayFunc(display);
	glutMainLoop();



	return 0;
}
