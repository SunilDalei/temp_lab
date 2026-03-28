#include<vector>
#include<utility>
#include <GL/glut.h>

using namespace std;

vector<pair<int,int>> arr;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display(int button, int state, int x, int y)
{
    if(state!=GLUT_DOWN) return;

    y = 500-y;
    glPointSize(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_LINE_STRIP);
        if(button==GLUT_LEFT_BUTTON) {
        	arr.push_back({x, y});
		for(auto &[x, y]: arr) {
			glVertex2f(x, y);
		}
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Click to Draw");

    init();
    glutMouseFunc(display);
    glutMainLoop();

    return 0;
}

