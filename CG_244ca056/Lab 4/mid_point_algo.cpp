#include<GL/glut.h>
#include<bits/stdc++.h> 

using namespace std;

int r;
int xc, yc;
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);
}

void display()
{   
   int x, y;
   x = 0;
   y = r;
   int p = 1 - r;
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 0.0f);
   glPointSize(2.0f);
   glBegin(GL_POINTS);
   while(x <= y)
   {
   	  glVertex2i(xc + x,yc + y);
	  glVertex2i(xc + y, yc + x);
	  glVertex2i(xc + y, yc - x);
	  glVertex2i(xc + x, yc - y);
	  glVertex2i(xc - x, yc - y);
	  glVertex2i(xc -y, yc - x);
	  glVertex2i(xc -y, yc + x);
	  glVertex2i(xc -x, yc + y);
   	if(p < 0)
   	{
   		p = p + 3 + 2 * x;
   		x = x + 1;
   	}
   	else
   	{
   		p = p + 1 + 2 * (x - y);
   		x += 1;
   		y -= 1;
   	}
   }
   glEnd();
   glFlush();
}   

int main(int argc, char** argv) {    
    cout <<"Enter the radius of the circle :";
    cin >> r;	 
    cout << "Enter center coords : " <<endl;
    cin >> xc >> yc;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Mid-point algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
