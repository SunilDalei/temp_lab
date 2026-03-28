#include<GL/glut.h>
#include<bits/stdc++.h> 

using namespace std;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

void display()
{   
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(1.0f);

    float x1 = 0.0f, y1 = 0.0f;
    float x2 = 0.0f, y2 = 50.0f;

    glBegin(GL_LINES);

    // 1. Initial Ladder
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);


    glColor3f(1.0f, 0.0f, 1.0f);
    // 2. Rotated ladder (bottom fixed)
    float theta = 30.0f;
    float rad = theta * M_PI / 180.0;

    // translate to origin (relative to bottom)
    float tx = x2 - x1;
    float ty = y2 - y1;

    // rotate
    float rx = cos(rad)*tx - sin(rad)*ty;
    float ry = sin(rad)*tx + cos(rad)*ty;

    // translate back
    float x2_rot = rx + x1;
    float y2_rot = ry + y1;

    glVertex2f(x1, y1);
    glVertex2f(x2_rot, y2_rot);


    glColor3f(0.0f, 1.0f, 0.0f);
    
    // 3. Translated ladder (entire ladder moves)
    float dx = 30.0f, dy = 20.0f;

    float x1_t = x1 + dx;
    float y1_t = y1 + dy;
    float x2_t = x2 + dx;
    float y2_t = y2 + dy;

    glVertex2f(x1_t, y1_t);
    glVertex2f(x2_t, y2_t);

    glEnd();
    glFlush();
}


int main(int argc, char** argv) {    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(300, 300);
    glutCreateWindow("Moving the ladder!");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
