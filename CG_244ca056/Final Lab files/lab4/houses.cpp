#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

float rx, ry, p1, p2, x, y;
float xc, yc;

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(1.0);
    
    p1 = ry*ry - rx*rx*ry + 0.25*rx*rx;
    x = 0, y = ry;

    glBegin(GL_POINTS);
    	while(ry*ry*x <= rx*rx*y) {
    		glVertex2f(xc+x, yc+y);
	    	printf("X: %f, Y: %f\n", (xc+x), (yc+y));
    		glVertex2f(xc+x, yc-y);
	    	printf("X: %f, Y: %f\n", (xc+x), (yc-y));
    		glVertex2f(xc-x, yc+y);
	    	printf("X: %f, Y: %f\n", (xc-x), (yc+y));
  	    	glVertex2f(xc-x,yc-y);    	
	    	printf("X: %f, Y: %f\n", (xc-x), (yc-y));
	    	
  	    	if(p1<0) {
  	    		p1 = p1 + ry*ry * (2*x + 3);
  	    		x++;
  	    	}
  	    	else {
  	    		p1 = p1 + ry*ry * (2*x + 3) - 2*rx*rx * (y-1);
  	    		x++;
  	    		y--;
  	    	}
	}
	p2 = ry*ry*(x + 0.5)*(x + 0.5) + rx*rx*(y - 1)*(y - 1) - rx*rx*ry*ry;
	while(y >= 0 ) {
		glVertex2f(xc+x, yc+y);
	    	printf("X: %f, Y: %f\n", (xc+x), (yc+y));
    		glVertex2f(xc+x, yc-y);
	    	printf("X: %f, Y: %f\n", (xc+x), (yc-y));
    		glVertex2f(xc-x, yc+y);
	    	printf("X: %f, Y: %f\n", (xc-x), (yc+y));
  	    	glVertex2f(xc-x,yc-y);    	
	    	printf("X: %f, Y: %f\n", (xc-x), (yc-y));
	    	
  	    	if (p2 > 0) {
			y--;
			    p2 = p2 - 2*rx*rx*y + rx*rx;
		}
		else {
		    x++;
		    y--;
		    p2 += 2*ry*ry*x - 2*rx*rx*y + rx*rx;
		}

	}
    glEnd();
    int numPoints = 100; // Increase for smoother circle
    glBegin(GL_LINE_LOOP); // Or GL_POLYGON for a filled circle
    for (int i = 0; i < numPoints; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numPoints);
        glVertex2f(x + radius * cosf(theta), y + radius * sinf(theta));
    }
    glFlush();

}



int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("scenery");		
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
