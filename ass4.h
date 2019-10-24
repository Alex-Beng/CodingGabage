#ifndef ASS4_H
#define ASS4_H

#include <bits/stdc++.h>
using namespace std;

#include "graphics.h"
#include "string.h"

int scx(double xj);
int scy(double yi);
double cal_x(double x, double y, double d);
double cal_y(double x, double y, double d);
void transfer(double dx, double dy);
void rotate(double theta);
void scale(double ss);
void reflect();
void axis();
void TestAss4();

#endif