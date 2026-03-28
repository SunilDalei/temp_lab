#include<vector>
#include<utility>
#include <GL/glut.h>

using namespace std;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f); 
    glPointSize(1.0f);
	
    glBegin(GL_LINES);
    	for(int y=200, x=0; x<=500; x+=50) {
        	glVertex2f(x, y);
   	        glVertex2f(x+50, (y==200)?300:200);
   	        y = (y==200)?300:200;
        }
        
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("zigzag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

