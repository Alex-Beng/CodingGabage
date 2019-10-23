#include "ass1.h"




int main(int argc, char const *argv[]) {
	int x0=0,y0=0,
	x1=450,y1=450,color=EGERGB(0, 0xff, 0);		//定义点(50,50)，(450,450)和颜色color
	int x,y;
	int gdriver=DETECT, gmode;	//定义图形驱动程序和显示模式
	initgraph(640, 480, 0);	//图形方式初始化
	cleardevice();

	setbkcolor(WHITE);

	x0=0,y0=0;
	MidPntCircle(x0, y0, 5, color);
	MidPntCircle(320, 240, 100, color);
	MidPntCircle(100, 80, 50, color);

	getch();
	BreshamCircle(x0, y0, 5, EGERGB(0xff, 0, 0));
	BreshamCircle(320, 240, 100, EGERGB(0xff, 0, 0));
	BreshamCircle(100, 80, 50, EGERGB(0xff, 0, 0));


	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();


	x0=50,y0=400,
	x1=500,y1=50;
	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();

	x0=50,y0=50,
	x1=300,y1=200;
	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();

	x0=50,y0=50,
	x1=300,y1=400;
	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();

	x0=200,y0=50,
	x1=200,y1=400;
	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();

	x0=200,y0=500,
	x1=100,y1=200;
	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();

	x0=300,y0=200,
	x1=50,y1=50;
	DDALine(x0, y0, x1, y1, color);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0));
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff));
	getch();
	
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
