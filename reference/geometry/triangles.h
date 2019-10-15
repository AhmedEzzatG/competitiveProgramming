#include"points.h"
#include"lines.h"
/*

A triangle with three sides: a, b, c has perimeter p = a + b + c and semi-perimeter
s = 0.5 × p

A triangle with 3 sides: a, b, c and semi-perimeter s has
area A = sqrt(s × (s − a) × (s − b) × (s − c));

A triangle with area A and semi-perimeter s has an inscribed circle (incircle) with
radius r = A/s

Law of Sines
a/sin(α) = b/ sin(b) = c/sin(c) = 2R
c^2= a^2 + b^2 − 2 × a × b × cos(γ)

A trapezium with a pair of parallel edges of lengths w1 and w2; and a height h between
both parallel edges has area A = 0.5 × (w1 + w2) × h
*/
// sin(A)/a = sin(B)/b = sin(C)/c
// a^2 = b^2 + c^2 - 2b*c*cos(A)

double getSide_a_bAB(double b, double A, double B) {
	return (sin(A) * b) / sin(B);
}

double getAngle_A_abB(double a, double b, double B) {
	return asin(fixAngle((a * sin(b)) / b));
}

// gave me WR answer in team formation :D 
double getAngle_A_abc(double a, double b, double c) {
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}
double perimeter_triangle(double a, double b, double c) {
	return a + b + c;
}
double area_triangle(double a, double b, double c) {
	double s = 0.5 * perimeter_triangle(a, b, c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
double triangleArea(point p0, point p1, point p2) {
	double a = length(vec(p1, p0)), b = length(vec(p2, p0)),
		c = length(vec(p2, p1));
	return triangleArea(a, b, c);
}
double rInCircle(double ab, double bc, double ca) {
	return area_triangle(ab, bc, ca) / (0.5 * perimeter_triangle(ab, bc, ca));
}
double rInCircle(point a, point b, point c) {
	return rInCircle(dist(a - b), dist(b - c), dist(c - a));
}
// Get radius and point of circle that inscribed with triangle
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point& ctr, double& r) {
	r = rInCircle(p1, p2, p3);
	if (fabs(r) < EPS) return 0; // no inCircle center
	line l1, l2; // compute these two angle bisectors
	double ratio = dist(p1 - p2) / dist(p1 - p3);
	point p = translate(p2, scale(vec(p2, p3), ratio / (1 + ratio)));
	pointsToLine(p1, p, l1);
	ratio = dist(p2 - p1) / dist(p2 - p3);
	p = translate(p1, scale(vec(p1, p3), ratio / (1 + ratio)));
	pointsToLine(p2, p, l2);
	areIntersect(l1, l2, ctr); // get their intersection point
	return 1;
}

double rCircumCircle(double ab, double bc, double ca) {
	return ab * bc * ca / (4.0 * area_triangle(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
	return rCircumCircle(dist(a - b), dist(b - c), dist(c - a));
}

double polygon_area(vector<point>points) {
	double area = 0;
	for (int i = 0; i < points.size() - 1; i++) {
		area += cp(vec(points[0], points[i]), vec(points[0], points[i + 1]));
		//area += area_triangle(dist(points[0] - points[i]), dist(points[0] - points[i+1]),
		//	dist(points[i] - points[i+1]));
		//point p1 = i ? points[i - 1] : points.back(),p2 = points[i];
		//area += (p1.X - p2.X) * (p1.Y + p2.Y);
	}
	return abs(area / 2.0);
}