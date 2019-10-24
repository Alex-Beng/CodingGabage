#ifndef ASS2_H
#define ASS2_H
#include <bits/stdc++.h>
using namespace std;

#include "graphics.h"
#include "string.h"

struct point {
    int x, y;
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};




void EdgeFill(std::vector<point> points);

void SeedFill(std::vector<point> points, point seed, int color);

#endif