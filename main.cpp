#include <bits/stdc++.h>
using namespace std;

#include "graphics.h"
#include "string.h"

// 只做abs(k) < 1的线
void _DDALine(int x0, int y0, int x1, int y1, int color) {
	float dx = x1-x0;
	float dy = y1-y0;
	float k;

	if (dx == 0) {
		int x = x0;
		for (int y=min(y0, y1); y<=max(y0, y1); y++) {
			putpixel(x, y, color);
		}
		return ;
	}

	if (dy <= dx) {
		k = dy/dx;
		int b_x, b_y;
		int e_x;
		if (x0 > x1) {
			b_x = x1;
			b_y = y1;
			e_x = x0;
		}
		else {
			b_x = x0;
			b_y = y0;
			e_x = x1;
		}

		int y=b_y;
		for (int x=b_x; x<=e_x; x++) {
			putpixel(x, (y+0.5), color);
			y += k;
		}
	}
	else {
		k = dx/dy;
		int b_x, b_y;
		int e_y;
		if (y0 > y1) {
			b_x = x1;
			b_y = y1;
			e_y = y0;
		}
		else {
			b_x = x0;
			b_y = y0;
			e_y = y1;
		}

		int x=b_x;
		for (int y=b_y; y<=e_y; y++) {
			putpixel((x+0.5), y, color);
			x += k;
		}
	}
}

void _MidPntLine(int x0, int y0, int x1, int y1, int color) {
	int a, b, d, delta_1, delta_2, x, y;
	a = y1-y0;
	b = x1-x0;
	if (a < b)
	d = 2*a + b;
	delta_1 = 2*a;
	delta_2 = 2*(a+b);

	x = x0;
	y = y0;
	putpixel(x, y, color);
	while (x < x1) {
		if (d < 0) {
			x++;
			y++;
			d += delta_2;
		}
		else {
			x++;
			d+=delta_1;
		}
		putpixel(x, y, color);
	}
}



int main(int argc, char const *argv[]) {
	int x0=0,y0=0,
	x1=450,y1=450,color=EGERGB(0, 0xff, 0);		//定义点(50,50)，(450,450)和颜色color
	int x,y;
	int gdriver=DETECT, gmode;	//定义图形驱动程序和显示模式
	initgraph(640, 480, 0);	//图形方式初始化

	setcolor(EGERGB(0xff, 0, 0));
	setbkcolor(WHITE);

	// DDALine(x0, y0, x1, y1, color);
	// getch();
	// color=EGERGB(0, 0xff,0xff);	
	// x0 = x1;
	// DDALine(x0, y0, x1, y1, color);

	// x0=0,y0=0,
	// x1=450,y1=0;
	// DDALine(x0, y0, x1, y1, color);
	// getch();
	// color=EGERGB(0, 0xff,0xff);	

	// x0=450,y0=0,
	// x1=0,y1=450;
	// DDALine(x0, y0, x1, y1, color);
	// getch();
	// color=EGERGB(0, 0xff,0xff);	
	
	// cleardevice();					//清屏
	// circle(320, 240, 100);
	// y=y0;
	// for(x=x0;x<=x1;x++)
	//    {
	// 	  putpixel(x,y,color);		//用colo颜色绘制点(x,y)
	// 	  y=y+1;
	//    }
	getch();						//让画面停住, 等按一下键盘再继续
	closegraph(); 					//关闭图形方式
	return 0;
}

