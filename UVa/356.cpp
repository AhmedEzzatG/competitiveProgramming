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
	int n;
	bool b = 0;
	while (cin >> n) {
		if (b)cout << endl;
		else b = 1;
		double r = n - 0.5;
		pair<int, int> cnt = { 0, 0 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				point p(i, j);
				double l1 = length(p);
				p = point(i + 1, j + 1);
				double l2 = length(p);
				if (l1 <= r && l2 <= r)
					cnt.second += 4;
				else if (l1 <= r && l2 > r)
					cnt.first += 4;
			}
		}
		cout << "In the case n = " << n << ", " << cnt.first
			<< " cells contain segments of the circle.\nThere are " <<
			cnt.second << " cells completely contained in the circle.\n";
	}
}
