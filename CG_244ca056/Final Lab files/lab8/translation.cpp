#include <GL/glut.h>

float vertices[8][3] = {
    {-0.5,-0.5,0.5}, {0.5,-0.5,0.5}, {0.5,0.5,0.5}, {-0.5,0.5,0.5},
    {-0.5,-0.5,-0.5}, {0.5,-0.5,-0.5}, {0.5,0.5,-0.5}, {-0.5,0.5,-0.5}
};

void drawCube(float v[8][3]) {
    glBegin(GL_LINES);
    for(int i=0; i < 4; i++) {
        glVertex3fv(v[i]); 
        glVertex3fv(v[(i + 1) % 4]);
        glVertex3fv(v[i + 4]);
        glVertex3fv(v[(i+1) % 4 + 4]);
        glVertex3fv(v[i]);
        glVertex3fv(v[i + 4]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(2, 2, 5, 0, 0, 0, 0, 1, 0);

    glColor3f(1.0, 0.0, 0.0);
    drawCube(vertices);

    float tx = 1.2, ty = 0.5, tz = -1.0;
    float translated[8][3];
    for(int i=0; i< 8; i++) {
        translated[i][0] = vertices[i][0] + tx;
        translated[i][1] = vertices[i][1] + ty;
        translated[i][2] = vertices[i][2] + tz;
    }

    glColor3f(0.0, 1.0, 0.0);
    drawCube(translated);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Translation");
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
