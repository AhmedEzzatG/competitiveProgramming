#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-8

struct point {
	double x, y;
	point() { x = 0, y = 0; }
	point(double a, double b) { x = a, y = b; }
};
double dis(point a, point b)
{
	double x = a.x - b.x, y = a.y - b.y;
	return sqrt(x * x + y * y);
}
point scale(point a, double x)
{
	return point(x * a.x, x * a.y);
}
point vec(point a, point b)
{
	return point(b.x - a.x, b.y - a.y);
}
point traslate(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
point rotation(point a, double ang)
{
	return point(a.x * cos(ang) - a.y * sin(ang), a.x * sin(ang) + a.y * cos(ang));
}
struct line {
	double a, b, c;
	line() { a = 0, b = 0, c = 0; }
	line(double x, double y, double z) { a = x, b = y, c = z; }
};
line update_line(line ret)
{
	if (ret.a < EPS || fabs(ret.a) < EPS && ret.b < EPS)
	{
		ret.a *= -1;
		ret.b *= -1; ret.c *= -1;
	}
	if (ret.a)
	{
		ret.b /= ret.a, ret.c /= ret.a; ret.a /= ret.a;
	}
	else if (ret.b)
	{
		ret.a /= ret.b, ret.c /= ret.b, ret.b /= ret.b;
	}
	else if (ret.c)
	{
		ret.a /= ret.c, ret.b /= ret.c, ret.c /= ret.c;
	}
	return ret;
}
double get_res_matrix(double a[2][2])
{
	return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}
point intersect_in_point(line a, line b)
{
	point c;
	double delta[2][2] = { {a.a,a.b},{b.a,b.b} };
	double delta_y[2][2] = { {a.c,a.b},{b.c,b.b} };
	double delta_x[2][2] = { {a.a,a.c},{b.a,b.c} };
	double del = get_res_matrix(delta);
	double del_x = get_res_matrix(delta_x);
	double del_y = get_res_matrix(delta_y);
	c = point(del_x / del, del_y / del);
	return c;
}
//p(t) = p(0) + t * (p(1) - p(0)) where t = dis(p(t), p(0)) / dis(p(1), p(0))