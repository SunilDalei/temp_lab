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


void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		glBegin(GL_POINTS);
		glVertex2i(x, 500 - y); 
  		glEnd();
  		glFlush();

	}
}

void solve(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  glPointSize(20.0);
  glutMouseFunc(mouse);
  
	

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
