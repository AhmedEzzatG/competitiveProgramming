#include"points.h"
#include"lines.h" //intersectSegments
#include"triangles.h" //getAngle_A_abc
/*
formala  (x-h) ^ 2 + (y-k)^2 = r^2
(h,k) is center, (x,y) any point in circle

// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
*/

//(x-h) ^ 2 + (y-k)^2 = r^2
bool is_insideCircle(point center, point b, double r) {
	double d1 = (b.X - center.X);
	double d2 = (b.Y - center.Y);
	return (d1 * d1 + d2 * d2) <= r * r;
}
bool circle2PtsRad(point p1, point p2, double r, point& c) {
	double d2 = (p1.X - p2.X) * (p1.X - p2.X) +
		(p1.Y - p2.Y) * (p1.Y - p2.Y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.real((p1.X + p2.X) * 0.5 + (p1.Y - p2.Y) * h);
	c.imag((p1.Y + p2.Y) * 0.5 + (p2.X - p1.X) * h);
	return true;
	// to get the other center, reverse p1 and p2
}
// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
pair<double, point> findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b + a) * 0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c) * 0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair(length(vec(center, a)), center);
}

// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
	double a = dp(vec(p0, p1), vec(p0, p1)), b = 2 * dp(vec(p0, p1), vec(C, p0)),
		c = dp(vec(C, p0), vec(C, p0)) - r * r;
	double f = b * b - 4 * a * c;
	vector<point> v;
	if (dcmp(f, 0) >= 0) {
		if (dcmp(f, 0) == 0)	f = 0;
		double t1 = (-b + sqrt(f)) / (2 * a);
		double t2 = (-b - sqrt(f)) / (2 * a);
		v.push_back(p0 + t1 * (p1 - p0));
		if (dcmp(f, 0) != 0)	v.push_back(p0 + t2 * (p1 - p0));
	}
	return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
	// Handle infinity case first: same center/radius and r > 0
	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return vector<point>(3, c1);    // infinity 2 same circles (not points)

	  // Compute 2 intersection case and handle 0, 1, 2 cases
	double ang1 = angle(vec(c1, c2)), ang2 = getAngle_A_abc(r2, r1, length(vec(c1, c2)));

	if (::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
		ang2 = 0; // fix corruption

	vector<point> v(1, polar(r1, ang1 + ang2) + c1);

	// if point NOT on the 2 circles = no intersection
	if (dcmp(dp(vec(c1, v[0]), vec(c1, v[0])), r1 * r1) != 0 ||
		dcmp(dp(vec(c2, v[0]), vec(c2, v[0])), r2 * r2) != 0)
		return vector<point>();

	v.push_back(polar(r1, ang1 - ang2) + c1);
	if (same(v[0], v[1]))  // if same, then 1 intersection only
		v.pop_back();
	return v;
}

bool is_intersect_circles(double x1, double y1, double r1, double x2, double y2, double r2) {
	double x = x1 - x2;
	double y = y1 - y2;
	double dist = sqrt(x * x + y * y);
	return dist < (r1 + r2) && (abs(r1 - r2) <= dist);
}
double distance(double x1, double y1, double x2, double y2) {
	double xx = (x1 - x2);
	double yy = (y1 - y2);
	return (xx * xx) + (yy * yy);
}
//get center point of line  with radious 
pair<double, double> center(double x1, double y1, double x2, double y2, double rr) {
	double ab = distance(x1, y1, x2, y2);
	double k = sqrt(rr / ab - 0.25);
	pair<double, double> o;
	o.first = (x1 + x2) / 2.0 + k * (y2 - y1);
	o.second = (y1 + y2) / 2.0 + k * (x1 - x2);
	return o;
}
// get smallest radious that contatin all points 
/*
const int MAX = 100000 + 9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs;	// ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);		rs = 0;
void MEC() {
if (ps == 0 && rs == 2) {
cen = (r[0] + r[1]) / 2.0;
rad = dist(r[0] - cen);
}
else if (rs == 3) {
pair<double, point> p = findCircle(r[0], r[1], r[2]);
cen = p.second;
rad = p.first;
}
else if (ps == 0) {
cen = r[0];	// sometime be garbage, but will not affect
rad = 0;
}
else {
ps--;
MEC();

if (dist(pnts[ps] - cen) > rad) {
r[rs++] = pnts[ps];
MEC();
rs--;
}

ps++;
}
}
*/