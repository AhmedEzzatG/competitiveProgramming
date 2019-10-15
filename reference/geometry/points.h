#include<bits/stdc++.h>
using namespace std;
/*
// Polar system , Cartesian
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2  + y^2)
O = atan2(y,x)
// Rotatet
x_  = cos(O) -sin(O) * x
y_  = sin(O) - cos(O) * y
//vectors
Vector = Direction + Magnitude
Two vectors are perpendicular if and only if their angle is a right angle
Set of vectors is orthogonal if and only if they are pairwise perpendicular
The normal vector to a surface is a vector which is perpendicular to the surface at a given point

Dot Product : Algebraically, sum of the products of the corresponding entries
Geometrically, the product of the Euclidean magnitudes of the two vectors
and the cosine of the angle between them.
A . B = |A| |B| cos(O) = x1*x2 + y1*y2
if A and B are orthogonal, then the angle between them is 90  A.B = 0
if they are codirectional, then the angle between them is 0   A.B = |A| |B|
if (O)  > 90 then A.B <0  and if(O) < 90 then A.B > 0 if (O) = 90 the A.B = 0

The cross product, a X b, is a vector that is perpendicular
to both a and b and therefore normal to the plane containing them.
-one if the two are perpendicular and a magnitude of zero if the two are parallel.
A x B  = A.x * B.y - B.x * A.y = r1 * r2 * sin(T2 - T1)

//complex numbers
point a(2,3)  >> norm(a)  = 2^2 + 3^2 = 13
conj(a)  >> 2 + 3i  > 2 -3i  flip sign i
*/
typedef complex<double> point;  // it can be long long not double
template<class T>
istream& operator>> (istream& is, complex<T>& p) {
	T value;
	is >> value;
	p.real(value);
	is >> value;
	p.imag(value);
	return is;
}
#define PI acos(-1.0)
#define EPS 1e-8
#define X real()   // can sign values point a; a.real(5) , a.image(2)
#define Y imag()
#define angle(a)  (atan2((a).imag(), (a).real())) // angle with orignial
#define dist(a)   (hypot((a).imag(), (a).real())) // distance between two point send diff
#define length(a) dist(a)
#define vec(a,b)  ((b)-(a)) // diff x1-x2 , y1-y2 return vec (x,y)
#define rotateO(p,ang)    ((p)*exp(point(0,ang)))  // angle should be in radian aroun origin
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)// rotate around point
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS) // check to points same or not
#define dp(a,b)   ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep dot product A.B
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
#define norm(a)  (norm(a))  // return x^2 + y^2 a is point can use dp(a,a)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define normalize(a)            (a)/dist(a)
double toRadians(double degree) {
	return (degree * PI) / 180.0;
}
int dcmp(long double x, long double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double fixMod(double a, double b) {
	return fmod(fmod(a, b) + b, b);
}
point translate(point p, point v) { // translate p according to v
	return point(p.X + v.X, p.Y + v.Y);
}
point scale(point v, double s) { // nonnegative s = [<1 .. 1 .. >1]
	return point(v.X * s, v.Y * s);
} // shorter.same.longer
// when sort points
bool cmp(point a, point b) {
	if (fabs(a.X - b.X) < EPS) {
		return a.Y < b.Y;
	}
	return a.X < b.X;
}
point reflect(point p, point p0, point p1) {
	point z = p - p0, w = p1 - p0;
	return conj(z / w) * w + p0;  // Refelect point p1 around p0p1
}
// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b) {
	point v1(a - O), v2(b - O);
	return acos(fixAngle(dp(v1, v2) / dist(v1) / dist(v2)));
}
double getAng(point& a, point& b, point& c) // find angle abc, anticlock bc to ba
{
	double ang = angle(vec(b, c)) - angle(vec(b, a));
	//if (dcmp(ang, 0) < 0)
	ang += 2 * PI;
	return ang;
}
