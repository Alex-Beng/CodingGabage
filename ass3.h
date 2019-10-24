#ifndef ASS3_H
#define ASS3_H


void bsp1_to_points(int degree, int L, float coeff[], float knot[], int dense, float points[]);
float deboor(int degree, float coeff[], float knot[], float u, int i);

void bez_to_points(int degree, int npoints, float coeff[], float points[]);
float decas(int degree, float coeff[], float t);

#endif