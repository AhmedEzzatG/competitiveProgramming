#include"point.h"

//o = anlge(a) - angle(b)
	//if o = 0 || o = 180 isCollinear
	//else not
bool isCollinear(point a, point b, point c) {
	return fabs(cp(vec(a, b), vec(a, c))) < EPS;
}
//o = anlge(a) - angle(b)
//if o = 0 isPointOnRay a->b
//else not
bool isPointOnRay(point a, point b, point c) {
	if (!isCollinear(a, b, c))
		return false;
	return dcmp(dp(vec(a, b), vec(a, c)), 0) == 1;
}

bool isPointOnRay(point a, point b, point c) {
	if (length(vec(a, c)) < EPS) return true;
	return same(normalize(vec(a, b)), normalize(vec(a, c)));
}

bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(vec(b, a)), ac = length(vec(c, a)), cb = length(vec(c, b));
	return dcmp(acb - (ac + cb), 0) == 0;
}

// dist point p2 to line p0-p1
double distToLine(point p0, point p1, point p2) {
	return fabs(cp(vec(p0, p1), vec(p0, p2)) / length(vec(p1, p0))); // area = 0.5*b*h
}

//minimum distance from point p2 to segment p0-p1
double distToSegment(point p0, point p1, point p2) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0)	return length(vec(p0, p2));
	if ((d2 = dp(v1, v1)) <= d1) return length(vec(p1, p2));
	double t = d1 / d2;
	return length(vec((p0 + v1 * t), p2));
}

// minimum point in segment po-p1 to point p2
point pointToSegment(point p0, point p1, point p2) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0)	return p0;
	if ((d2 = dp(v1, v1)) <= d1) return p1;
	double t = d1 / d2;
	return (p0 + v1 * t);
}

// return point intersect in line a-b with c-d using parametric equations 
bool intersectSegments(point a, point b, point c, point d, point& intersect) {
	double d1 = cp(vec(b, a), vec(c, d)), d2 = cp(vec(c, a), vec(c, d)), d3 = cp(vec(b, a), vec(c, a));
	if (fabs(d1) < EPS)
		return false;  // Parllel || identical

	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;

	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
	return true;
}

// return 1 if point c is counter-clockwise about segment a-b
// -1 if point c is clockwise about segment a-b
// 0 if c is isCollinear about a-b
int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > EPS)
		return 1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return 1;
	return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
	// special case handling if a segment is just a point
	bool x = (p1 == p2), y = (p3 == p4);
	if (x && y)  return p1 == p3;
	if (x)   return ccw(p3, p4, p1) == 0;
	if (y)   return ccw(p1, p2, p3) == 0;
	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

bool lineInsideRectangle(double x1, double x2, double y1, double y2, point st, point ed) {
	if (x2 < x1) swap(x1, x2);
	if (y2 < y1) swap(y1, y2);
	double mnX = min(st.X, ed.X), mxX = max(st.X, ed.X),
		mnY = min(st.Y, ed.Y), mxY = (st.Y, ed.Y);
	return dcmp(x1, mnX) <= 0 && dcmp(x2, mxX) >= 0 && dcmp(y1, mnY) <= 0 && dcmp(y2, mxY) >= 0;
}