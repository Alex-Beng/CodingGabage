#include "ass4.h"

#include "graphics.h"
#include "math.h"
#include "stdio.h"

double xmax = 639.0, ymax = 399.0;
double f[3][3], xx, yy;

int scx(double xj)
{ //坐标轴坐标转化为窗口坐标
    int x;
    x = (int)(xj + xmax / 2);
    return (x);
}

int scy(double yi)
{
    int y;
    y = int(ymax - (int)(yi + (ymax / 2)));
    return (y);
}

double cal_x(double x, double y, double d)
{
    xx = x * f[0][0] + y * f[1][0] + d * f[2][0];
    return (xx);
}

double cal_y(double x, double y, double d)
{
    yy = x * f[0][1] + y * f[1][1] + d * f[2][1];
    return (yy);
}

void transfer(double dx, double dy)
{ // 平移
    f[0][0] = 1.0;
    f[0][1] = 0.0;
    f[0][2] = 0.0;
    f[1][0] = 0.0;
    f[1][1] = 1.0;
    f[1][2] = 0.0;
    f[2][0] = dx;
    f[2][1] = dy;
    f[2][2] = 1.0;
}

void rotate(double theta)
{ //旋转
    double th;
    th = theta / 180 * 3.1415927;
    f[0][0] = cos(th);
    f[0][1] = sin(th);
    f[0][2] = 0.0;
    f[1][0] = -sin(th);
    f[1][1] = cos(th);
    f[1][2] = 0.0;
    f[2][0] = 0.0;
    f[2][1] = 0.0;
    f[2][2] = 1.0;
}

void scale(double ss)
{ //放缩
    f[0][0] = ss;
    f[0][1] = 0.0;
    f[0][2] = 0.0;
    f[1][0] = 0.0;
    f[1][1] = ss;
    f[1][2] = 0.0;
    f[2][0] = 0.0;
    f[2][1] = 0.0;
    f[2][2] = 1.0;
}

void reflect() //对称
{
    f[0][0] = -1.0;
    f[0][1] = 0.0;
    f[0][2] = 0.0;
    f[1][0] = 0.0;
    f[1][1] = -1.0;
    f[1][2] = 0.0;
    f[2][0] = 0.0;
    f[2][1] = 0.0;
    f[2][2] = 1.0;
}

void axis()
{
    line(scx(0), scy(-ymax / 2), scx(0), scy(ymax / 2));
    line(scx(-xmax / 2), scy(0.0), scx(xmax / 2), scy(0.0));
}

void TestAss4()
{
    int driver = DETECT, mode, i, r = 60;
    static double x1[] = { 0.0, 100.0, 80.0, 80.0, 0.0 };
    static double y1[] = { 10.0, 0.0, 50.0, 50.0, 10.0 };
    static double x2[5], y2[5], x3[5], y3[5], x4[5], y4[5], x5[5], y5[5];
    initgraph(640, 480, 0);

    axis();
    getch(); //画坐标轴
    for (i = 0; i <= 3; i++) {
        line(scx(x1[i]), scy(y1[i]), scx(x1[i + 1]), scy(y1[i + 1]));
    } //画基本图形,这里是一个三角形

    getch();
    scale(2.0); //放大

    for (i = 0; i <= 4; i++) {
        x2[i] = cal_x(x1[i], y1[i], 1.0);
        y2[i] = cal_y(x1[i], y1[i], 1.0);
    }

    for (i = 0; i <= 3; i++) {
        line(scx(x2[i]), scy(y2[i]), scx(x2[i + 1]), scy(y2[i + 1]));
    }

    getch();
    rotate(135.0); //旋转45°

    for (i = 0; i <= 4; i++) {
        x3[i] = cal_x(x2[i], y2[i], 1.0);
        y3[i] = cal_y(x2[i], y2[i], 1.0);
    }
    for (i = 0; i <= 3; i++) {
        line(scx(x3[i]), scy(y3[i]), scx(x3[i + 1]), scy(y3[i + 1]));
    }

    getch();
    transfer(50.0, -100.0); //平移

    for (i = 0; i <= 4; i++) {
        x4[i] = cal_x(x1[i], y1[i], 1.0);
        y4[i] = cal_y(x1[i], y1[i], 1.0);
    }

    for (i = 0; i <= 3; i++) {
        line(scx(x4[i]), scy(y4[i]), scx(x4[i + 1]), scy(y4[i + 1]));
    }

    getch(); //对称
    reflect();

    for (i = 0; i <= 4; i++) {
        x5[i] = cal_x(x1[i], y1[i], 1.0);
        y5[i] = cal_y(x1[i], y1[i], 1.0);
        Sleep(100);
    }
    for (i = 0; i <= 3; i++) {
        line(scx(x5[i]), scy(y5[i]), scx(x5[i + 1]), scy(y5[i + 1]));
    }

    getch();
    closegraph();

}
