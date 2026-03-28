#include<graphics.h>
#include<stdio.h>

int main() {
	int gd = DETECT, gm, color;
	initgraph(&gd, &gm, "");
	putpixel(85, 35, GREEN);
	getch();
	closegraph();
	return 0;
}
