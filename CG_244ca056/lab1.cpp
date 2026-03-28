#include<GL/glut.h>
#include<bits/stdc++.h>

void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void print(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  usleep(3000);
  glEnd();
  glFlush();
}
void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  glPointSize(20.0);
  //glBegin(GL_POINTS);
  //glVertex2i(250, 250);
  int count = 4;
  int l = 300;
  int b = 200;
  int x = 150;
  int y = 100;
  for(int i = y ; i <= y + l; i++)
  {
     print(x, i);
  }
  for(int i = x; i <= x + b; i++)
  {
     print(i, y + l);
  }
  for(int i = y+l; i >= y; i--)
  {
    print(x + b, i);
  }
  for(int i = x+b; i >= x ; i--)
  {
    print(i , y);
  }
  
  
  
  
 // glVertex2i(75, 150);
 // glVertex2i(100, 200);
  
}


int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Draw point Example ");
  init();
  glutDisplayFunc(display);
  glutMainLoop();


  return 0;
}
