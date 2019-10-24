#ifndef ASS2_H
#define ASS2_H
#include <bits/stdc++.h>
using namespace std;

#include "graphics.h"
#include "string.h"

#define LEFT    (int)(1)
#define RIGHT   (int)(2)
#define BOTTON  (int)(4)
#define TOP     (int)(8)

struct point {
    int x, y;
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


void EdgeFill(std::vector<point> points);

void SeedFill(std::vector<point> points, point seed, int color);

int _PntEncoder(float x, float y, float XL, float XR, float YB, float YT);

void CsLineCutter(float x1, float y1, float x2, float y2, float XL, float XR, float YB, float YT);

#endif