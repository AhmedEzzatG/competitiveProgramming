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
typedef complex<int> point;
#define X real()
#define Y imag()
#define vec(a,b) (b - a)
#define angle(a) (atan2(a.Y,a.X))

struct cmp {
	bool operator ()(const point& a, const point& b) const {
		if (a.X != b.X) return a.X < b.X;
		return a.Y < b.Y;
	}
};
int gcd(int a, int b) { return !b ? abs(a) : gcd(b, a % b); }


int main() {
	run();
	int t; cin >> t;
	cin.ignore();
	string s;
	getline(cin, s);
	while (t--) {
		vector<point> v;
		while (getline(cin, s)) {
			if (s.empty())break;
			int x, y;
			stringstream ss;
			ss << s;
			ss >> x >> y;
			v.push_back(point(x, y));
		}
		int n = sz(v), mx = 1;
		for (int i = 0; i < n; i++) {
			map<point, int, cmp> mp;
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				point p = vec(v[i], v[j]);
				int g = gcd(p.X, p.Y);
				if (g) p /= g;
				if (p.Y < 0)p *= -1;
				mp[p]++;
				mx = max(mx, mp[p]);
			}
		}
		cout << mx + 1 << endl;
		if (t)cout << endl;
	}
}
