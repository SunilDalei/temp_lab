#include<vector>
#include<utility>
#include<GL/glut.h>
#include<iostream> 

using namespace std;

float x1, y_1, x2, y2, p;
    
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{       
    float p, x = x1, y = y_1;
    float dx = abs(x2 - x1), dy = abs(y2 - y_1);

    int x_inc = (x2 >= x1) ? 1 : -1;
    int y_inc = (y2 >= y_1) ? 1 : -1;
    
    int count = 0;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0f);
    glBegin(GL_POINTS);

    if (dy <= dx) { 
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++, count++) {
    	    if((count%9 < 4) || (count%9 == 6)) {
  		cout << "( " << x << ", " << y << " )\n";
	       	glVertex2i(x, y);
            }
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
        for (int i = 0; i <= dy; i++, count++) {
    	    if((count%9 < 4) || (count%9 == 6)) {
  		cout << "( " << x << ", " << y << " )\n";
	       	glVertex2i(x, y);
            }
            if (p >= 0) {
                x += x_inc;      
                p -= 2 * dy;     
            }
            y += y_inc;          
            p += 2 * dx;         
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
    glutCreateWindow("Dashed Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
