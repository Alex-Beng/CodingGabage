#ifndef ASS1_H
#define ASS1_H
#include <bits/stdc++.h>
using namespace std;

#include "graphics.h"
#include "string.h"

// 无限宽，竖直刷，水平刷
enum {LINE_LI_VERI, LINE_LI_HORI};
enum {LINE_SHAPE_NONE, LINE_SHAPE_DOT, LINE_SHAPE_CHAIN};

inline void _LineBrush(int x, int y, int w, int color, int flag);

void _VetiLine(int x0, int y0, int x1, int y1, int color, int w, int shape);

// 三种画线方法
void _DDALine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys, int shape);
void DDALine(int x0, int y0, int x1, int y1, int color, int w, int shape);

void _MidPntLine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys, int shape);
void MidPntLine(int x0, int y0, int x1, int y1, int color, int w, int shape);

void _BreshamLine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys, int shape);
void BreshamLine(int x0, int y0, int x1, int y1, int color, int w, int shape);

// 画圆的工具函数
inline void _DrawCircle(int x0, int y0, int x, int y, int color);

// 两种画圆的方法
void MidPntCircle(int x0, int y0, int r, int color);
void BreshamCircle(int x0, int y0, int r, int color);


#endif