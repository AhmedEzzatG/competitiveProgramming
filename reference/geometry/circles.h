#include"point.h"
#include"triangles.h" //getAngle_A_abc
#include"lines.h" //intersectSegments

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