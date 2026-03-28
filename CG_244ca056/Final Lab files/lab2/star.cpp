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
	
    vector<pair<int, int>> arr = {{50, 300}, {150, 300}, {200, 400},
    	{250, 300}, {350, 300}, {275, 225}, {300, 100}, {200, 175},
    	{100, 100}, {125, 225} 
    
    };
    
	
    glBegin(GL_LINE_LOOP);
    	for(int i=0; i<arr.size()-1; i++) { 
        	glVertex2f(arr[i].first, arr[i].second);
        	glVertex2f(arr[i+1].first, arr[i+1].second);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Star");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

