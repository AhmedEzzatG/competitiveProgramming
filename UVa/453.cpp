#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const ll oo = LLONG_MAX, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-4;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
#endif
}
typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b) (b - a)
#define dp(a,b) ((conj(a)*b).X)
#define cp(a,b) ((conj(a)*b).Y)
#define length(a) (hypot(a.Y,a.X))
#define angle(a) (atan2(a.Y,a.X))

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
bool same(point p1, point p2) {
	return dp(vec(p1, p2), vec(p1, p2)) < EPS;
}
double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double getAngle_A_abc(double a, double b, double c) {
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return vector<point>(3, c1);
	double ang1 = angle(vec(c1, c2)), ang2 = getAngle_A_abc(r2, r1, length(vec(c1, c2)));
	if (::isnan(ang2)) ang2 = 0;
	vector<point> v(1, polar(r1, ang1 + ang2) + c1);
	if (dcmp(dp(vec(c1, v[0]), vec(c1, v[0])), r1* r1) != 0 ||
		dcmp(dp(vec(c2, v[0]), vec(c2, v[0])), r2 * r2) != 0)
		return vector<point>();
	v.push_back(polar(r1, ang1 - ang2) + c1);
	if (same(v[0], v[1])) v.pop_back();
	return v;
}
point min(point a, point b) {
	if (a.X < b.X)return a;
	if (a.X == b.X) {
		if (a.Y < b.Y)return a;
		return b;
	}
	return b;
}
point max(point a, point b) {
	if (a.X  > b.X)return a;
	if (a.X == b.X) {
		if (a.Y > b.Y)return a;
		return b;
	}
	return b;
}
int main() {
	run();
	cout << fixed << setprecision(3);
	double x, y, r;
	while (cin >> x >> y >> r) {
		point c1 = { x,y };
		double r2;
		cin >> x >> y >> r2;
		point c2 = { x,y };
		vector<point> v = intersectCircleCircle(c1, r, c2, r2);
		if (sz(v) == 3)
			cout << "THE CIRCLES ARE THE SAME";
		else if (v.empty())cout << "NO INTERSECTION";
		else {
			for (int i = 0; i < sz(v); i++) {
				if (dcmp(v[i].X, 0.0) == 0)
					v[i] = { 0.0,v[i].Y };
				if (dcmp(v[i].Y, 0.0) == 0)
					v[i] = { v[i].X,0.0 };
			}
			if (sz(v) == 1) cout << v[0];
			else cout << min(v[0], v[1]) << max(v[0], v[1]);
		}
		cout << endl;
	}
}
