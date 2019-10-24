#include "ass1.h"
#include "ass2.h"
#include "ass3.h"

int TestAss1() {
	int x0=0,y0=0,
	x1=450,y1=450,color=EGERGB(0, 0xff, 0);		//?????(50,50)??(450,450)?????color
	int x,y;
	int gdriver=DETECT, gmode;	//?????????????????????
	initgraph(640, 480, 0);	//??��???????
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


	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();


	x0=50,y0=400,
	x1=500,y1=50;
	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();

	x0=50,y0=50,
	x1=300,y1=200;
	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();

	x0=50,y0=50,
	x1=300,y1=400;
	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();

	x0=200,y0=50,
	x1=200,y1=400;
	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();

	x0=200,y0=500,
	x1=100,y1=200;
	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();

	x0=300,y0=200,
	x1=50,y1=50;
	DDALine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
	getch();
	MidPntLine(x0, y0, x1, y1, EGERGB(0xff, 0, 0), 2, LINE_SHAPE_DOT);
	getch();
	BreshamLine(x0, y0, x1, y1, EGERGB(0, 0, 0xff), 3, LINE_SHAPE_CHAIN);
	getch();
	
	// cleardevice();					//????
	// circle(320, 240, 100);
	// y=y0;
	// for(x=x0;x<=x1;x++)
	//    {
	// 	  putpixel(x,y,color);		//??colo????????(x,y)
	// 	  y=y+1;
	//    }
	getch();						//???????, ??????????????
	closegraph(); 					//?????��??
	return 0;
}

int TestAss2() {
	initgraph(640, 480, 0);	
	cleardevice();
	setbkcolor(WHITE);

	std::vector<point> pnts;
	pnts.push_back(point(0, 0));
	pnts.push_back(point(0, 100));
	pnts.push_back(point(100, 0));
	// EdgeFill(pnts);


	// pnts.resize(5);
	pnts[0] = point(200, 0);
	pnts[1] = point(400, 0);
	pnts[2] = point(400, 300);
	pnts.push_back(point(300, 60));
	pnts.push_back(point(200, 120));
	
	SeedFill(pnts, point(300, 10), EGERGB(0xff, 0xff, 0));
	getch();
	EdgeFill(pnts);

	getch();	

	// test cut
	MidPntLine(0, 50, 150, 50, EGERGB(0, 0xff, 0), 1, LINE_SHAPE_NONE);
	MidPntLine(0, 100, 150, 100, EGERGB(0, 0xff, 0), 1, LINE_SHAPE_NONE);
	MidPntLine(50, 0, 50, 150, EGERGB(0, 0xff, 0), 1, LINE_SHAPE_NONE);
	MidPntLine(100, 0, 100, 150, EGERGB(0, 0xff, 0), 1, LINE_SHAPE_NONE);

	getch();

	CsLineCutter(75, 25, 120, 99, 50, 100, 50, 100);
	getch();

	closegraph(); 
	return 0;
}

int TestAss3() {
	initgraph(640, 480, 0);	
	cleardevice();
	setbkcolor(WHITE);

	float Xcoeff[7] = {20, 60, 100, 300, 340, 380,};
	float Ycoeff[7] = {250, 200, 150, 100, 150, 200, 250,};
	float Xpoints[2333];
	float Ypoints[2333];
	int degree = 3;
	int n = 700;
	bez_to_points(degree, n, Xcoeff, Xpoints);
	bez_to_points(degree, n, Ycoeff, Ypoints);

	setcolor(EGERGB(0, 0xff, 0));
	for (int i=0; i<n; i++) {
		if (i>0) {
			line(Xpoints[i - 1], Ypoints[i - 1], Xpoints[i], Ypoints[i]);
		}
	}
	getch();

	int dense = 200;
	n = 7;
	degree = 3;
	int L = n-degree;
	float knot[16] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12};

	bsp1_to_points(degree, L, Xcoeff, knot, dense, Xpoints);
	bsp1_to_points(degree, L, Ycoeff, knot, dense, Ypoints);

	setcolor(EGERGB(0, 0, 0xff));
	for (int i=0; i<L*dense; i++) {
		if (i>0) {
			line(Xpoints[i - 1], Ypoints[i - 1], Xpoints[i], Ypoints[i]);
		}
	}

	getch();
	closegraph(); 
	return 0;
}

int main(int argc, char const *argv[]) {
	// cout<<hex<<EGERGBA(0xff, 0xff, 0xff, 0);
	// TestAss1();
	// TestAss2();
	TestAss3();
	return 0;
}
