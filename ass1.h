#ifndef ASS1_H
#define ASS1_H
#include <bits/stdc++.h>
using namespace std;

#include "graphics.h"
#include "string.h"

// 三种画线方法
void _DDALine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys);
void DDALine(int x0, int y0, int x1, int y1, int color);

void _MidPntLine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys);
void MidPntLine(int x0, int y0, int x1, int y1, int color);

void _BreshamLine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys);
void BreshamLine(int x0, int y0, int x1, int y1, int color);

// 画圆的工具函数
inline void _DrawCircle(int x0, int y0, int x, int y, int color);

// 两种画圆的方法
void MidPntCircle(int x0, int y0, int r, int color);
void BreshamCircle(int x0, int y0, int r, int color);



#endif