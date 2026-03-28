#include<vector>
#include<utility>
#include <GL/glut.h>
#include<cstdlib>

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
    
    vector<pair<int, int>> arr;
    
    for(int i=0, j=250; i<=500; i+=50) 
    	arr.push_back(make_pair(i, (rand()%500)));
    
	
    glBegin(GL_LINE_STRIP);
    	for(int i=0; i<arr.size(); i++) 
        	glVertex2f(arr[i].first, arr[i].second);
        
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Strip");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

