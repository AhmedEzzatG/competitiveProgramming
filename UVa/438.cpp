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
#define cp(a,b) ((conj(a)*b).Y)
#define length(a) (hypot(a.Y,a.X))

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

double findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b + a) * 0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c) * 0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return length(vec(center, a));
}

int main() {
	run();
	cout << fixed << setprecision(2);
	double x, y;
	while (cin >> x >> y) {
		vector<point> v(3);
		v[0] = { x,y };
		for (int i = 1; i < 3; i++) {
			cin >> x >> y;
			v[i] = { x,y };
		}
		double r = findCircle(v[0], v[1], v[2]);
		cout << r * 2 * PI << endl;
	}
}
