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
  for(int i = 1; i < points.size(); i++)
  {
    glVertex2i(points[i-1][0], points[i-1][1]);
    glVertex2i(points[i][0], points[i][1]);
  }
  glEnd();
  glFlush();

}
int main(int argc, char **argv)
{
  int n;
  cout << "ENter the number of points : " << endl;
  cin >> n;
  for(int i = 0;i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    points.push_back({x,y});
    
  }
  
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
 glutInitWindowSize(500, 500);
 glutCreateWindow("Question 1");
 init();
 glutDisplayFunc(solve);
 glutMainLoop();
 return 0;
}
