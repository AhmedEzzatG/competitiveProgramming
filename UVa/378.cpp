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
typedef complex<double> point;
typedef pair<int, int> pii;
#define X real()
#define Y imag()
#define length(a) (hypot(a.Y,a.X))
#define vec(a,b) (b - a)
#define normalize(a) (a/(length(a)))
#define dp(a,b) ((conj(a)*b).X)	// a*b cos(T), if zero -> prep
#define cp(a,b) ((conj(a)*b).Y) // a*b sin(T), if zero -> parllel
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
double fixMod(double a, double b) {
	return fmod(fmod(a, b) + b, b);
}
bool isCollinear(point a, point b, point c) {
	return fabs(cp(vec(a, b), vec(a, c))) < EPS;
}
bool intersectSegments(point a, point b, point c, point d, point& intersect) {
	double d1 = cp(vec(b, a), vec(c, d)), d2 = cp(vec(c, a), vec(c, d)), d3 = cp(vec(b, a), vec(c, a));
	if (fabs(d1) < EPS)
		return false;
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;
	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;
	return true;
}
int main() {
	run();
	cout << fixed << setprecision(2);
	cout << "INTERSECTING LINES OUTPUT\n";
	int n; cin >> n;
	while (n--) {
		point p[4];
		for (int i = 0; i < 4; i++) {
			double x, y;
			cin >> x >> y;
			p[i] = { x,y };
		}
		point v1 = vec(p[1], p[0]), v2 = vec(p[3], p[2]), ans;
		if (cp(v1, v2) == 0) {
			if (isCollinear(p[0], p[1], p[2]) || isCollinear(p[0], p[1], p[3]))
				cout << "LINE" << endl;
			else
				cout << "NONE" << endl;
		}
		else {
			intersectSegments(p[0], p[1], p[2], p[3], ans);
			cout << "POINT " << ans.X << ' ' << ans.Y << endl;
		}
	}
	cout << "END OF OUTPUT\n";
}
