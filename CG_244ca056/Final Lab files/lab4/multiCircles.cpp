#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

vector<pair<float, float>> centers;
vector<float> radii;

void init()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    
    glBegin(GL_POINTS);
    	for(int i=0; i<radii.size(); i++) {
    	    float p = 1-radii[i], x = 0, y = radii[i];
    	    while(x<=y) {
    		glVertex2i(centers[i].first+x, centers[i].second+y);
    		glVertex2i(centers[i].first+x, centers[i].second-y);
    		glVertex2i(centers[i].first-x, centers[i].second+y);
  	    	glVertex2i(centers[i].first-x, centers[i].second-y);    	
  	    	glVertex2i(centers[i].first+y, centers[i].second+x);
  	    	glVertex2i(centers[i].first-y, centers[i].second+x);
  	    	glVertex2i(centers[i].first+y, centers[i].second-x);
  	    	glVertex2i(centers[i].first-y, centers[i].second-x);
  	    	if(p<0) {
  	    		p = p + 2 * x + 3;
  	    		x++;
  	    	}
  	    	else {
  	    		p = p + 2 * (x-y) + 1;
  	    		x++;
  	    		y--;
  	    	}
  	    }
	}
    glEnd();
    glFlush();
}



int main(int argc, char ** argv){
	int n;
	cout << "Enter the number of circles: ";
	cin >> n;
	radii.resize(n);
	centers.resize(n);
	for(int i=0; i<n; i++) {
		cout << "Enter the radius: ";
		cin >> radii[i];
		cout << "Enter the coordinates of center: ";
		cin >> centers[i].first >> centers[i].second;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Mid point Circle Algorithm");		
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
