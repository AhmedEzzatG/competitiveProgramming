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
int main() {
	run();
	cout << fixed << setprecision(3);
	point p[4];
	double x, y;
	while (cin >> x >> y) {
		p[0] = point(x, y);
		for (int i = 1; i < 4; i++) {
			cin >> x >> y;
			p[i] = point(x, y);
		}
		vector<int> v;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (p[i] == p[j]) {
					for (int k = 0; k < 4; k++) {
						if (k == i || k == j)continue;
						v.push_back(k);
					}
					v.push_back(i);
				}
			}
		}
		point ans = p[v[0]] + p[v[1]] - p[v[2]];
		cout << ans.X << ' ' << ans.Y << endl;
	}
}
