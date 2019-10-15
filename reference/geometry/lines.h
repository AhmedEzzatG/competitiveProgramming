#include"points.h"
/*
equation
explicit 2D  y = mx + b  , m = (y2-y1)/(x2-x1) ,get b from given point1, or point2
Implicit 2D  ax + by + c = 0  . a = y1 - y2 , b = x2 - x1 , c = x1y2 - x2y1
Parametric  P(t) = P0 + tVL
collinear if slop1 = slop2
perpendicular  if slop1 * slop2 = -1

if point is over line or not
y = mx + c  , point (x0,y0) get m , c
y0 - mx0+c > 0 then above
y0 - mx0+c < 0 the below
y0 - mx0+c = 0  then over

intersection of two lines
y1= mx1 + c1 , y2 = mx2 + c2
mx1+c1 = mx2 + c2  get x2 then get y1 from any equation

*/
struct line {
	double a, b, c;
};
void pointsToLine(point p1, point p2, line& l) {
	if (fabs(p1.X - p2.X) < EPS) { // vertical line is fine
		l.a = 1.0; l.b = 0.0; l.c = -p1.X; // default values
	}
	else {
		l.a = -(double)(p1.Y - p2.Y) / (p1.X - p2.X);
		l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
		l.c = -(double)(l.a * p1.X) - p1.Y;
	}
}
bool areParallel(line l1, line l2) { // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) { // also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point& p) {
	if (areParallel(l1, l2)) return false; // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.real((l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b));
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.imag(-(l1.a * p.X + l1.c));
	else p.imag(-(l2.a * p.X + l2.c));
	return true;
}
bool isCollinear(point a, point b, point c) {
	return fabs(cp(b - a, c - a)) < EPS;
}
// point c inRay a-b->
bool isPointOnRay(point a, point b, point c) {
	if (dist(vec(a, c)) < EPS) return true;
	return same(normalize(vec(a, b)), normalize(vec(a, c)));
}
// point c inSegment a-b
bool isPointOnSegment(point a, point b, point c) {
	double acb = length(vec(b, a)), ac = length(vec(c, a)), cb = length(vec(c, b));
	return dcmp(acb - (ac + cb), 0) == 0;
}
// dist point p2 to line p0-p1
double distToLine(point p0, point p1, point p2) {
	return fabs(cp(p1 - p0, p2 - p0) / dist(p0 - p1)); // area = 0.5*b*h
}
// distance from point p2 to segment p0-p1
// p4 is the nearest point to p2
double distToSegment(point p0, point p1, point p2, point& p4) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0) {
		p4 = p0;
		return dist(p2 - p0);
	}
	if ((d2 = dp(v1, v1)) <= d1) {
		p4 = p1;
		return dist(p2 - p1);
	}
	double t = d1 / d2;
	p4 = (p0 + v1 * t);  // this is point 
	return dist(p2 - (p0 + v1 * t));
}
bool intersectSegments(point a, point b, point c, point d, point& intersect) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;  // Parllel || identical

	double t1 = (double)d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;

	if (t1 > 1 + EPS || t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
	return true;
}
// Where is c relative to segment a-b?
// ccw = +1 => angle > 0 or collinear after b 
// point c is counter-clockwise about segment a-b
// cw = -1 => angle < 0 or collinear after a
// point c is clockwise about segment a-b
// Undefined = 0 => Collinar in range [a, b]. Be careful here
int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return 1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
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