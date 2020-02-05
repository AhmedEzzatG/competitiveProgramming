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
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
#endif
}
typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b) (b - a)
#define length(a) (hypot(a.Y,a.X))
#define cp(a,b) ((conj(a)*b).Y)
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > EPS)
		return 1;
	if (t < -EPS)
		return -1;
	if (v1.X* v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return 1;
	return 0;
}
bool intersect(point p1, point p2, point p3, point p4) {
	bool x = (p1 == p2), y = (p3 == p4);
	if (x&& y)  return p1 == p3;
	if (x)   return ccw(p3, p4, p1) == 0;
	if (y)   return ccw(p1, p2, p3) == 0;

	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
bool lineInSideRectangle(double x1, double x2, double y1, double y2, point st,point ed) {
	if (x2 < x1) swap(x1, x2);
	if (y2 < y1) swap(y1, y2);
	double mnX = min(st.X, ed.X), mxX = max(st.X, ed.X),
		mnY = min(st.Y, ed.Y), mxY = (st.Y, ed.Y);
	return dcmp(x1, mnX) <= 0 && dcmp(x2, mxX) >= 0 && dcmp(y1, mnY) <= 0 && dcmp(y2, mxY) >= 0;

}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		double x, y, xx, yy;
		cin >> x >> y;
		point st = { x,y };
		cin >> x >> y;
		point ed = { x,y };
		cin >> x >> y >> xx >> yy;
		if (x > xx)swap(x, xx);
		if (y > yy)swap(y, yy);
		bool b = lineInSideRectangle(x, xx, yy, y, st, ed)
			|| intersect(st, ed, { x,y }, { xx,y })
			|| intersect(st, ed, { x,y }, { x,yy })
			|| intersect(st, ed, { x,yy }, { xx,yy })
			|| intersect(st, ed, { xx,y }, { xx,yy });
		cout << (b ? "T" : "F") << endl;
	}
}
