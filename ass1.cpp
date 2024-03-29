#include "ass1.h"

inline void _LineBrush(int x, int y, int w, int color, int flag) {
    if (flag == LINE_LI_VERI) {
        int r_w = w/2 + 1;
        for (int t=y-w/2; t<y+r_w; t++) {
            putpixel(x, t, color);
        }
    }
    else if (flag == LINE_LI_HORI) {
        int r_w = w/2 + 1;
        for (int t=x-w/2; t<x+r_w; t++) {
            putpixel(t, y, color);
        }
    }
}

void _VetiLine(int x0, int y0, int x1, int y1, int color, int w, int shape) {
    if (y0 > y1) {
		swap(x0, x1);
		swap(y0, y1);
	}

    for (int y=y0; y<=y1; y++) {
        if (shape == LINE_SHAPE_NONE) {
            _LineBrush(x0, y, w, color, LINE_LI_HORI);
        }
        else if (shape == LINE_SHAPE_DOT) {
            if ( ((y-y0)/32)%2 == 0 ) {
                _LineBrush(x0, y, w, color, LINE_LI_HORI);
            }
        }
        else if (shape == LINE_SHAPE_CHAIN) {
            if ( ((y-y0)/32)%2 == 0 ) {
                _LineBrush(x0, y, w, color, LINE_LI_HORI);
            }
            else if ( (y-y0)%32 > 32/4 && (y-y0)%32 < 3*32/4 ){
                _LineBrush(x0, y, w, color, LINE_LI_HORI);
            }
        }
	}

}

// 只做abs(k) < 1的线
void _DDALine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys, int shape) {
	float dx = x1-x0;
	float dy = y1-y0;
	float k = dy/dx;

    float cos = dx/sqrt(dx*dx + dy*dy);
    int margin = 32*cos;

	float y=y0;
	for (int x=x0; x<=x1; x++) {
        if (shape == LINE_SHAPE_NONE) {
            xs[x-x0] = x;
            ys[x-x0] = int(y+0.5);
        }
        else if (shape == LINE_SHAPE_DOT) {
            if ( ((x-x0)/margin)%2 == 0 ) {
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
        }
        else if (shape == LINE_SHAPE_CHAIN) {
            if ( ((x-x0)/margin)%2 == 0 ) {
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
            else if ( (x-x0)%margin > margin/4 && (x-x0)%margin < 3*margin/4 ){
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
        }
		y += k;
	}
}

void DDALine(int x0, int y0, int x1, int y1, int color, int w=1, int shape=LINE_SHAPE_NONE) {
	if (x0 > x1) {
		swap(x0, x1);
		swap(y0, y1);
	}

	int dx = x1-x0;
	int dy = y1-y0;

	// 斜率不存在特判
	if (dx == 0) {
        _VetiLine(x0, y0, x1, y1, color, w, shape);
		return ;
	}

	double k = 1.0*dy/dx;
	int* xs;
	int* ys;

	if (abs(k) > 1) {
		
		swap(x0, y0);
		swap(x1, y1);

		dx = abs(x0-x1);
		xs = new int[dx+1];
		ys = new int[dx+1];
		_DDALine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
            _LineBrush(ys[i], xs[i], w, color, LINE_LI_HORI);
		}
	}
	else {
		dx = abs(x0-x1);
		xs = new int[dx+1];
		ys = new int[dx+1];
		_DDALine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
            _LineBrush(xs[i], ys[i], w, color, LINE_LI_VERI);
		}
	}
	return ;
}

// 只做0 < k < 1 的线
void _MidPntLine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys, int shape) {
    float dx = x1-x0;
	float dy = y1-y0;
	float k = dy/dx;

    float cos = dx/sqrt(dx*dx + dy*dy);
    int margin = 32*cos;
    
	int a, b, d, delta_1, delta_2, x, y;
	a = y0-y1;
	b = x1-x0;
	
	d = 2*a + b;
	delta_1 = 2*a;
	delta_2 = 2*(a+b);

	x = x0;
	y = y0;

	xs[x-x0] = x;
	ys[x-x0] = y;

	while (x < x1) {
		if (d < 0) {
			x++;
			y++;
			d += delta_2;
		}
		else {
			x++;
			d += delta_1;
		}

		if (shape == LINE_SHAPE_NONE) {
            xs[x-x0] = x;
            ys[x-x0] = int(y+0.5);
        }
        else if (shape == LINE_SHAPE_DOT) {
            if ( ((x-x0)/margin)%2 == 0 ) {
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
        }
        else if (shape == LINE_SHAPE_CHAIN) {
            if ( ((x-x0)/margin)%2 == 0 ) {
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
            else if ( (x-x0)%margin > margin/4 && (x-x0)%margin < 3*margin/4 ){
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
        }
	}
}

void MidPntLine(int x0, int y0, int x1, int y1, int color, int w=1, int shape=LINE_SHAPE_NONE) {
	if (x0 > x1) {
		swap(x0, x1);
		swap(y0, y1);
	}

	int dx = x1-x0;
	int dy = y1-y0;

	if (dx == 0) {
        _VetiLine(x0, y0, x1, y1, color, w, shape);
		return ;
	}

	double k = 1.0*dy/dx;

	int* xs;
	int* ys;

	if (0<=k && k<=1) {
		xs = new int[dx+1];
		ys = new int[dx+1];
		_MidPntLine(x0, y0, x1, y1, xs, ys, shape);
	}
	else if (-1<=k && k<0) {
		y0 = -y0;
		y1 = -y1;

		xs = new int[dx+1];
		ys = new int[dx+1];
		_MidPntLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(xs[i], -ys[i], w, color, LINE_LI_HORI);
		}
		return ;
	}
	else if (k > 1) {
		swap(x0, y0);
		swap(x1, y1);

		dx = abs(x0-x1);
		xs = new int[dx+1];
		ys = new int[dx+1];
		_MidPntLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(ys[i], xs[i], w, color, LINE_LI_VERI);
		}
		return ;
	}
	else if (k < -1) {
		swap(x0, y0);
		swap(x1, y1);
		y0 = -y0;
		y1 = -y1;

		dx = abs(x0-x1);
		xs = new int[dx+1];
		ys = new int[dx+1];
		_MidPntLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(-ys[i], xs[i], w, color, LINE_LI_HORI);
		}
		return ;
	}

	for (int i=0; i<=dx; i++) {
		_LineBrush(xs[i], ys[i], w, color, LINE_LI_HORI);
	}
}

// 只做0 < k < 1 的线
void _BreshamLine(int x0, int y0, int x1, int y1, 
				int* xs, int* ys, int shape) {
	int x, y, dx, dy, e;
	dx = x1 - x0;
	dy = y1 - y0;

    float cos = 1.0*dx/sqrt(1.0*dx*dx + dy*dy);
    int margin = 32*cos;

	e = -dx;
	x = x0;
	y = y0;
	for (int i=0; i<=dx; i++) {
		if (shape == LINE_SHAPE_NONE) {
            xs[x-x0] = x;
            ys[x-x0] = int(y+0.5);
        }
        else if (shape == LINE_SHAPE_DOT) {
            if ( ((x-x0)/margin)%2 == 0 ) {
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
        }
        else if (shape == LINE_SHAPE_CHAIN) {
            if ( ((x-x0)/margin)%2 == 0 ) {
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
            else if ( (x-x0)%margin > margin/4 && (x-x0)%margin < 3*margin/4 ){
                xs[x-x0] = x;
                ys[x-x0] = int(y+0.5);
            }
        }

		x++;
		e += 2*dy;
		if (e >= 0) {
			y++;
			e -= 2*dx;
		}
	}
}

void BreshamLine(int x0, int y0, int x1, int y1, int color, int w=1, int shape=LINE_SHAPE_NONE) {
	if (x0 > x1) {
		swap(x0, x1);
		swap(y0, y1);
	}

	int dx = x1-x0;
	int dy = y1-y0;

	if (dx == 0) {
        _VetiLine(x0, y0, x1, y1, color, w, shape);
		return ;
	}

	double k = 1.0*dy/dx;

	int* xs;
	int* ys;

	if (0<=k && k<=1) {
		xs = new int[dx+1];
		ys = new int[dx+1];
		_BreshamLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(xs[i], ys[i], w, color, LINE_LI_HORI);
		}
	}
	else if (-1<=k && k<0) {
		y0 = -y0;
		y1 = -y1;

		xs = new int[dx+1];
		ys = new int[dx+1];
		_BreshamLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(xs[i], -ys[i], w, color, LINE_LI_HORI);
		}
		return ;
	}
	else if (k > 1) {
		swap(x0, y0);
		swap(x1, y1);

		dx = abs(x0-x1);
		xs = new int[dx+1];
		ys = new int[dx+1];
		_BreshamLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(ys[i], xs[i], w, color, LINE_LI_VERI);
		}
		return ;
	}
	else if (k < -1) {
		swap(x0, y0);
		swap(x1, y1);
		y0 = -y0;
		y1 = -y1;

		dx = abs(x0-x1);
		xs = new int[dx+1];
		ys = new int[dx+1];
		_BreshamLine(x0, y0, x1, y1, xs, ys, shape);
		for (int i=0; i<=dx; i++) {
			_LineBrush(-ys[i], xs[i], w, color, LINE_LI_VERI);
		}
		return ;
	}


}

inline void _DrawCircle(int x0, int y0, int x, int y, int color) {
	putpixel(x0+x, y0+y, color);
	putpixel(x0+y, y0+x, color);

	putpixel(x0+x, y0-y, color);
	putpixel(x0-y, y0+x, color);

	putpixel(x0-x, y0+y, color);
	putpixel(x0+y, y0-x, color);

	putpixel(x0-x, y0-y, color);
	putpixel(x0-y, y0-x, color);
}



void MidPntCircle(int x0, int y0, int r, int color) {
	int x, y, delta_x, delta_y, d;
	x = 0, y = r;
	delta_x = 3;
	delta_y = 2-r-r;
	d = 1-r;
	_DrawCircle(x0, y0, x, y, color);
	while (x < y) {
		if (d < 0) {
			d+= delta_x;
			delta_x += 2;
			x++;
		}
		else {
			d += (delta_x+delta_y);
			delta_x += 2;
			delta_y += 2;
			x++;
			y--;
		}
		_DrawCircle(x0, y0, x, y, color);
	}
	
}

void BreshamCircle(int x0, int y0, int r, int color) {
	int x, y, delta, delta_1, delta_2, direction;
	x = 0, y = r;
	delta = 2*(1-r);
	while (y >= x) {
		_DrawCircle(x0, y0, x, y, color);
		if (delta < 0) {
			delta_1 = 2*(delta+y) - 1;
			if (delta_1 < 0) {
				direction = 1;
			}
			else {
				direction = 2;
			}
		}
		else if (delta > 0) {
			delta_2 = 2*(delta-x)-1;
			if (delta_2 <= 0) {
				direction = 2;
			}
			else {
				direction = 3;
			}
		}
		else {
			direction = 2;
		}

		switch (direction)
		{
		case 1:
			x++;
			delta += 2*x + 1;
			break;
		case 2:
			x++;
			y--;
			delta += 2*(x-y+1);
			break;
		case 3:
			y--;
			delta += (-2*y+1);
			break;
		default:
			break;
		}
	}
}

