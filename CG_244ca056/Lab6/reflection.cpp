#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

void init()
{
 	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
 	glMatrixMode(GL_PROJECTION);
 	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float x1 = 100.0f, y1 = 300.0f;
    float x2 = 400.0f, y2 = 350.0f;

    // Reflection matrices
    float refX[2][2] = {{1, 0}, {0, -1}};
    float refY[2][2] = {{-1, 0}, {0, 1}};

    // 1. Original line
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // 2. Reflection about X-axis
    float rx1 = refX[0][0]*x1 + refX[0][1]*y1;
    float ry1 = refX[1][0]*x1 + refX[1][1]*y1;

    float rx2 = refX[0][0]*x2 + refX[0][1]*y2;
    float ry2 = refX[1][0]*x2 + refX[1][1]*y2;

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(rx1, ry1);
    glVertex2f(rx2, ry2);
    glEnd();

    // 3. Reflection about Y-axis (on result of X reflection)
    rx1 = refY[0][0]*x1 + refY[0][1]*y1;
    ry1 = refY[1][0]*x1 + refY[1][1]*y1;
    
    rx2 = refY[0][0]*x2 + refY[0][1]*y2;
    ry2 = refY[1][0]*x2 + refY[1][1]*y2;

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(rx1, ry1);
    glVertex2f(rx2, ry2);
    glEnd();

    glFlush();
        
}
int main(int argc, char **argv)
{	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Reflection of a line w.r.t x and y axis");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

	
}
