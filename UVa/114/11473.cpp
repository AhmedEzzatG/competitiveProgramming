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
const double PI = acos(-1), EPS = 1e-7;
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
#define length(a) (hypot(a.Y,a.X))
#define dp(a,b) ((conj(a)*b).X)
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int main() {
	run();
	cout << fixed << setprecision(2);
	int t; cin >> t;
	int I = 1;
	while (t--) {
		cout << "Road #" << I++ << ":\n";
		int n, m;
		cin >> n >> m;
		vector<point> v(n);
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			v[i] = point(x, y);
		}
		cout << v[0].X << ' ' << v[0].Y << endl;
		if (m >= 2) {
			vector<double> l(n + 1);
			for (int i = 1; i < n; i++) {
				l[i] = length(vec(v[i - 1], v[i]));
			}
			for (int i = 1; i < n; i++) {
				l[i] += l[i - 1];
			}
			double dis, d;
			dis = d = l[n - 1] / (m - 1);
			for (int i = 1; i < n; i++) {
				while (dcmp(dis, l[i]) <= 0) {
					point v1 = vec(v[i - 1], v[i]);
					v1 *= (dis - l[i - 1]) / (l[i] - l[i - 1]);
					v1 += v[i - 1];
					dis += d;
					cout << v1.X << ' ' << v1.Y << endl;
				}
			}
		}
		cout << endl;
	}

}
