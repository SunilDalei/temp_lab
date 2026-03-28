
#include <GL/glut.h>

/* Initialization function */
void init()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);   // Red background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

/* Display callback function */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow color
    glPointSize(10.0f);

    glBegin(GL_POINTS);
        glVertex2i(50, 100);
        glVertex2i(75, 100);
        glVertex2i(100, 200);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Draw Point");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

