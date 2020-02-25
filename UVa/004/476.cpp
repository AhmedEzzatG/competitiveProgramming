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
const double PI = acos(-1), EPS = 1e-1;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}
typedef complex<double> point;
#define X real()
#define Y imag()
struct rec {
	double x1, x2, y1, y2;
};
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

bool pointInsideRectangle(rec& r, point p) {
	if (r.x2 < r.x1) swap(r.x1, r.x2);
	if (r.y2 < r.y1) swap(r.y1, r.y2);
	return (r.x1 < p.X && p.X < r.x2 && r.y1 < p.Y && p.Y < r.y2);
}

int main() {
	run();
	char ch;
	vector<rec> v;
	while (cin >> ch, ch != '*') {
		rec r;
		cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
		v.push_back(r);
	}
	double x, y; int I = 1;
	while (cin >> x >> y, x != 9999.9 || y != 9999.9) {
		point p(x, y);
		bool b = 1;
		for (int i = 0; i < sz(v); i++) {
			if (pointInsideRectangle(v[i], p)) {
				printf("Point %d is contained in figure %d\n", I, i + 1);
				b = 0;
			}
		}
		if (b) printf("Point %d is not contained in any figure\n", I);
		I++;
	}
}
