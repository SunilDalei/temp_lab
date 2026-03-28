#include<vector>
#include<utility>
#include<GL/glut.h>
#include<iostream> 

using namespace std;
    
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{   
    float p;
    vector<vector<int>> lines = {{100, 300, 100, 200}, {100, 250, 140, 250}, {140, 300, 140, 200}, // Letter H
    				{150, 300, 150, 200}, {150, 300, 190, 300}, {150, 250, 180, 250}, {150, 200, 190, 200}, // Letter E
    				{200, 300, 200, 200}, {200, 200, 240, 200}, // Letter L
    				{250, 300, 250, 200}, {250, 200, 290, 200}, // Letter L
    				{300, 300, 360, 300}, {300, 300, 300, 200}, {300, 200, 360, 200}, {360, 200, 360, 300} // Letter O
    };
    for(auto &vec: lines) {
    	float x1 = vec[0], y_1 = vec[1], x2 = vec[2], y2 = vec[3];
    	float x = x1, y = y_1;
    	float dx = abs(x2 - x1), dy = abs(y2 - y_1);

    	int x_inc = (x2 >= x1) ? 1 : -1;
    	int y_inc = (y2 >= y_1) ? 1 : -1;

   	glClear(GL_COLOR_BUFFER_BIT);
    	glColor3f(0.0f, 0.0f, 0.0f);
    	glPointSize(3.0f);
  	glBegin(GL_POINTS);

    if (dy <= dx) { 
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            glVertex2i(x, y);
            if (p >= 0) {
                y += y_inc; 
                p -= 2 * dx;
            }
            x += x_inc;
            p += 2 * dy;         
        }
    } 
    else {
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            glVertex2i(x, y);
            if (p >= 0) {
                x += x_inc;      
                p -= 2 * dy;     
            }
            y += y_inc;          
            p += 2 * dx;         
        }
    }
    }

    glEnd();
    glFlush();
}   

int main(int argc, char** argv) {    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("HELLO");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
