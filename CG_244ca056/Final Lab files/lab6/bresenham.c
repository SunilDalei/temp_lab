#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void bresenham(int x1, int y1, int x2, int y2) {
	float p, m = (y2-y1)/(float)(x2-x1);
	int dx = x2-x1, dy = y2-y1, x = x1, y = y1;
	
	if(m<1) {
		p = 2*dy-dx;
		while(x<x2) {
			putpixel(x, y, WHITE);
			if(p>=0) {
				p += 2*dy - dx;
				y++;
			}
			else p += 2*dy;
			x++;
		}
	}
	else {
		p = 2*dx-dy;
		while(y<y2) {
			putpixel(x, y, WHITE);
			if(p>=0) {
				p += 2*dx - dy;
				x++;
			}
			else p += 2*dx;
			y++;
		}		
	}
}

int main() {
	int gd = DETECT, gm, color;
	int x1, x2, y1, y2;
	printf("Enter the coordinates of starting and terminal points: ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	initgraph(&gd, &gm, "");
	
	bresenham(x1, y1, x2, y2);
	getch();
	closegraph();
	return 0;
}
