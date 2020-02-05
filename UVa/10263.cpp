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
const int oo = INT_MAX, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}
typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b) (b - a)
#define dp(a,b) ((conj(a)*b).X)
#define lengthSqr(a) (dp(a,a))
point solve(point p0, point p1, point p2) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0)	return p0;
	if ((d2 = dp(v1, v1)) <= d1) return p1;
	double t = d1 / d2;
	return (p0 + v1 * t);
}
int main() {
	run();
	cout << fixed << setprecision(4);
	double x, y; int n;
	while (cin >> x >> y >> n) {
		point p(x, y);
		cin >> x >> y;
		point st(x, y), ans;
		double mn = DBL_MAX;
		if (n == 0) ans = st;
		while (n--) {
			cin >> x >> y;
			point ed(x, y);
			st = solve(st, ed, p);
			double d = lengthSqr(vec(st, p));
			if (d < mn) { mn = d; ans = st; }
			st = ed;
		}
		cout << ans.X << endl << ans.Y << endl;
	}
}
