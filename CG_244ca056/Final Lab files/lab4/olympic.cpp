#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

vector<pair<float, float>> centers = {{380, 525}, {500, 525}, {620, 525}, {440, 480}, {560, 480}};
float radius = 50.0f;
vector<vector<float>> colors = {{0.0,0.0,1.0}, {0.0,0.0,0.0}, {1.0,0.0,.0}, {1.0,1.0,0.0},{0.0,1.0,0.0}};

void init()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.0);
    
    glBegin(GL_POINTS);
    	for(int i=0; i<centers.size(); i++) {
    	    glColor3f(colors[i][0],colors[i][1],colors[i][2]);
    	    float p = 1-radius, x = 0, y = radius;
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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Mid point Circle Algorithm");		
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
