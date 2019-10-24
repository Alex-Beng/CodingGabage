#include "ass2.h"


void EdgeFill(std::vector<point> points) {
    int line_nums = points.size();
    cout<<line_nums<<endl;

    int minx = 999;
    int maxx = -1;
    int miny = 999;
    int maxy = -1;

    for (int i=0; i<line_nums; i++) {
        int x = points[i].x;
        int y = points[i].y;
        if (x < minx) {
            minx = x;
        }
        if (x > maxx) {
            maxx = x;
        }
        if (y < miny) {
            miny = y;
        }
        if (y > maxy) {
            maxy = y;
        }
    }


    for (int i=0; i<line_nums; i++) {
        int x0 = points[i].x;
        int y0 = points[i].y;
        int x1 = points[(i+1)%line_nums].x;
        int y1 = points[(i+1)%line_nums].y;
        cout<<x0<<' '<<y0<<' '<<x1<<' '<<y1<<endl;

        int dx = x1-x0;
        int dy = y1-y0;

        // 特判一下斜率不存在
        if (dx == 0) {
            if (y0 > y1) {
                swap(x0, x1);
                swap(y0, y1);
            }
            for (int y=y0; y<=y1; y++) {
                for (int x=x0; x<maxx; x++) {
                    putpixel(x, y, 0xffffff-getpixel(x, y));
                }
            }
            continue;
        }

        if (abs(dy) > abs(dx)) {
            double k = 1.0*dx/dy;
            if (y0 > y1) {
                swap(x0, x1);
                swap(y0, y1);
            }

            float x = x0;
            for (int y=y0; y<=y1; y++) {
                for (int t=int(x+0.5); t<=maxx; t++) {
                    putpixel(t, y, 0xffffff-getpixel(t, y));
                }
                x += k;
                // getch();
            }
        }
        else {
            double k = 1.0*dy/dx;

            if (x0 > x1) {
                swap(x0, x1);
                swap(y0, y1);
            }

            float y = y0;
            for (int x=x0; x<=x1; x++) {
                for (int t=int(y+0.5); t<=maxy; t++) {
                    putpixel(x, t, 0xffffff-getpixel(x, t));
                }
                y += k;
            }
        }
        getch();
    }
}