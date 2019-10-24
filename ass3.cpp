#include "ass3.h"


void bsp1_to_points(int degree, int L, float coeff[], float knot[], int dense, float points[])
{

	int i, ii;
	float u = 0;
	int point_num = 0;

	for (i = degree - 1; i < L + degree - 1; i++)
	{
		if (knot[i + 1] > knot[i])
		{
			for (ii = 0; ii < dense; ii++)
			{
				u = knot[i] + ii * (knot[i + 1] - knot[i]) / dense;
				points[point_num] = deboor(degree, coeff, knot, u, i);
				point_num++;
			}
		}
	}
}

float deboor(int degree, float coeff[], float knot[], float u, int i)
{
	int k, j;
	float t1, t2;
	float coeffa[30];
	for (j = i - degree + 1; j <= i + 1; j++)
	coeffa[j] = coeff[j];
	for (k = 1; k <= degree; k++)
	{
		for (j = i + 1; j >= i - degree + k + 1; j--)
		{
			t1 = (knot[j + degree - k] - u) / (knot[j + degree - k] - knot[j - 1]);
			t2 = 1.0 - t1;
			coeffa[j] = t1 * coeffa[j - 1] + t2 * coeffa[j];
		}
	}
	return (coeffa[i + 1]);
}


void bez_to_points(int degree, int npoints, float coeff[], float points[]) {
    float t, delt;
    int i;
    delt = 1.0/npoints;
    t = 0;
    for (int i=0; i<=npoints; i++) {
        points[i] = decas(degree, coeff, t);
        t += delt;
    }
}


float decas(int degree, float coeff[], float t) {
    int r, i;
    float t1;
    float coeffa[10];
    t1 = 1-t;
    for (i=0; i<=degree; i++) {
        coeffa[i] = coeff[i];
    }

    for (r=1; r<=degree; r++) {
        for (i=0; i<=degree-r; i++) {
            coeffa[i] = t1*coeffa[i] + t*coeffa[i+1];
        }
    }
    return coeffa[0];
}