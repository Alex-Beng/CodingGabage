#include "ass1.h"
#include "ass2.h"

int delta[][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0,
};

void EdgeFill(std::vector<point> points) {
    int line_nums = points.size();
    // cout<<line_nums<<endl;

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
        // cout<<x0<<' '<<y0<<' '<<x1<<' '<<y1<<endl;

        int dx = x1-x0;
        int dy = y1-y0;

        // 特判一下斜率不存在
        if (dx == 0) {
            if (y0 > y1) {
                swap(x0, x1);
                swap(y0, y1);
            }
            for (int y=y0; y<y1; y++) {
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
                for (int t=int(x+0.5); t<maxx; t++) {
                    putpixel(t, y, 0xffffff-getpixel(t, y));
                }
                x += k;
                // getch();
            }
            for (int t=x1; t<maxx; t++) {
                putpixel(t, y1, 0xffffff-getpixel(t, y1));
            }
        }
        else {
            double k = 1.0*dy/dx;

            if (x0 > x1) {
                swap(x0, x1);
                swap(y0, y1);
            }

            std::map<int, int> map_for_fill;
            float y = y0;
            for (int x=x0; x<=x1; x++) {
                map_for_fill[int(y+0.5)] = x;
                // for (int t=int(y+0.5); t<=maxy; t++) {
                //     // putpixel(x, t, 0xffffff-getpixel(x, t));
                //     map_for_fill[y] = x;
                // }
                y += k;
            }

            if (y0 > y1) {
                swap(x0, x1);
                swap(y0, y1);
            }
            for (int t_y=y0; t_y<y1; t_y++) {
                for (int t_x=map_for_fill[t_y]; t_x<maxx; t_x++) {
                    putpixel(t_x, t_y, 0xffffff-getpixel(t_x, t_y));
                }
                // getch();
            }
        }
        // getch();
    }
}



void SeedFill(std::vector<point> points, point seed, int color) {
    // 绘制边界
    int line_nums = points.size();
    for (int i=0; i<line_nums; i++) {
        int x0 = points[i].x;
        int y0 = points[i].y;
        int x1 = points[(i+1)%line_nums].x;
        int y1 = points[(i+1)%line_nums].y;
        cout<<x0<<' '<<y0<<' '<<x1<<' '<<y1<<endl;

        MidPntLine(x0, y0, x1, y1, color, 1, LINE_SHAPE_NONE);
        // getch();
    }
    std::stack<point> sk;
    sk.push(seed);

    while (!sk.empty()) {
        point t = sk.top();
        sk.pop();
        // cout<<t.x<<t.y;
        putpixel(t.x, t.y, color);
        // getch();
        for (int i=0; i<4; i++) {
            int x = t.x+delta[i][0];
            int y = t.y+delta[i][1];
            if (getpixel(x, y) == color) { // 边界点不要管
                continue ;
            }
            else if (getpixel(x, y) == WHITE) {
                sk.push(point(x, y));
            }
        }
    }
}