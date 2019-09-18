#include"point.h"

// sin(A)/a = sin(B)/b = sin(C)/c
// a^2 = b^2 + c^2 - 2b*c*cos(A)

double getSide_a_bAB(double b, double A, double B) {
	return (sin(A) * b) / sin(B);
}

double getAngle_A_abB(double a, double b, double B) {
	return asin(fixAngle((a * sin(b)) / b));
}

// wr answer in team formation :D 
double getAngle_A_abc(double a, double b, double c) {
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}

double triangleArea(double a, double b, double c) {
	double s = (a + b + c) / 2.0;
	return sqrt((s - a) * (s - b) * (s - c) * s);
}

double triangleArea(point p0, point p1, point p2) {
	double a = length(vec(p1, p0)), b = length(vec(p2, p0)),
		c = length(vec(p2, p1));
	return triangleArea(a, b, c);
}