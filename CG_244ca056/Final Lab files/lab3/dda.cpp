#include<vector>
#include<utility>
#include<GL/glut.h>
#include<iostream> 

using namespace std;

float x1, y_1, x2, y2;
    
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{   
    float x = x1, y=y_1;
    float m = (y2-y_1)/(float)(x2-x1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f); 
    glPointSize(1.0f);
    
    cout << "Points rendered...\n";
    glBegin(GL_POINTS);
    	while(x<=x2 && y<=y2) {
        	glVertex2i(x, y);
    	        cout << "( " << x << ", " << y << " )\n";
        	if(m<=1) {
        		x = x + 1;
        		y = m + y;
        	}
        	else {
        		x = (1 + m * x) / m;
        		y++;
        	}
        }
        
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter the starting point coordinates: ";
    cin >> x1 >> y_1;
    cout << "Enter the end point coordinates: ";
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
