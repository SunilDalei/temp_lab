#include<vector>
#include<utility>
#include<GL/glut.h>
#include<cmath>
#include<iostream>

using namespace std;

float angle;
int n;

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
    
    for(int i=0, j=0, k=0; k<n; k++) {
    	float rotate = angle*k;
    	i = 250 + 100.0f * cos(rotate);
    	j = 250 + 100.0f * sin(rotate);
    	arr.push_back(make_pair(i, j));
    }
    
	
    glBegin(GL_POLYGON);
    	for(int i=0; i<arr.size(); i++) 
        	glVertex2f(arr[i].first, arr[i].second);
        
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter number of sides in polygon: ";
    cin >> n;
    angle = 2.0f * (M_PI)/n;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

