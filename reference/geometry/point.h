#include<bits/stdc++.h>
using namespace std;
typedef complex<double> point;
#define PI acos(-1)
#define EPS 1e-8
#define X real()
#define Y imag()
#define vec(a,b) (b - a)
#define length(a) (hypot(a.Y,a.X))
#define angle(a) (atan2(a.Y,a.X))
#define normalize(a) (a/(length(a)))
#define dp(a,b) ((conj(a)*b).X)	// a*b cos(T), if zero -> prep
#define cp(a,b) ((conj(a)*b).Y) // a*b sin(T), if zero -> parllel
#define lengthSqr(a) (dp(a,a))

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

double fixMod(double a, double b) {
	return fmod(fmod(a, b) + b, b);
}

bool same(point p1, point p2) {
	return dp(vec(p1, p2), vec(p1, p2)) < EPS;
}

point rotateO(point p, double ang) {
	return p * exp(point(0, ang));
}

point rotate(point p, double ang, point about) {
	return rotateO(vec(about, p), ang) + about;
}

// Refelect v around m
point reflectO(point v, point m) {
	return conj(v / m) * m;
}

// Refelect v around m 
point reflect(point v, point m, point about) {
	point z = vec(about, v), w = vec(about, m);
	return reflectO(z, w) + about;
}