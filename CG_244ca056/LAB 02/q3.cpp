#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;
vector<vector<int>> points;
void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}


void solve(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  glPointSize(20.0);
  glBegin(GL_LINES);
  int y1 = 200;
  int y2 = 300;
    	for(int x=0; x<=500; x+=50) {
        	glVertex2i(x, y1);
   	        glVertex2i(x+50, y2);
   	        swap(y1, y2);
        }
  glEnd();
  glFlush();

}
int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
 glutInitWindowSize(500, 500);
 glutCreateWindow("Question 1");
 init();
 glutDisplayFunc(solve);
 glutMainLoop();
 return 0;
}
