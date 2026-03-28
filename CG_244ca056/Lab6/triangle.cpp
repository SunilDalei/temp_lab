#include<GL/glut.h>
#include<bits/stdc++.h> 

using namespace std;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-150, 150, -150, 150);
}

void display()
{   
    glClear(GL_COLOR_BUFFER_BIT);

    vector<pair<float, float>> vertices = {
        {10.0f, 20.0f}, {20.0f, 40.0f}, {30.0f, 20.0f}
    };

    vector<pair<float, float>> points(3);

    float theta = 30.0f;
    float rad = theta * M_PI / 180.0;

    // 1. Original Triangle
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    for(auto [x, y]: vertices)
        glVertex3f(x, y, 0.0f);
    glEnd();

    // 2. Rotated about origin
    for(int i = 0; i < 3; i++) {
        points[i].first  = cos(rad)*vertices[i].first - sin(rad)*vertices[i].second;
        points[i].second = sin(rad)*vertices[i].first + cos(rad)*vertices[i].second;
    }

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    for(auto [x, y]: points)
        glVertex3f(x, y, 0.0f);
    glEnd();

    // 3. Rotated about fixed point
    float fx = 10.0f, fy = 15.0f;

    for(int i = 0; i < 3; i++) {
        float tx = vertices[i].first - fx;
        float ty = vertices[i].second - fy;

        float rx = cos(rad)*tx - sin(rad)*ty;
        float ry = sin(rad)*tx + cos(rad)*ty;

        points[i].first  = rx + fx;
        points[i].second = ry + fy;
    }

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    for(auto [x, y]: points)
        glVertex3f(x, y, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(300, 300);
    glutCreateWindow("Rotating the Triangle!");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
