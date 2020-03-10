#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
typedef complex<double> point;
template<class T>
istream& operator>>(istream &is, complex<T> &p) {
	T value;
	is >> value;
	p.real(value);
	is >> value;
	p.imag(value);
	return is;
}
#define PI acos(-1.0)
#define EPS 1e-8
#define X real()
#define Y imag()
#define cp(a,b)   ( (conj(a)*(b)).imag() )
int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return 1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}
bool intersect(point p1, point p2, point p3, point p4) {
	bool x = (p1 == p2), y = (p3 == p4);
	if (x && y)
		return p1 == p3;
	if (x)
		return ccw(p3, p4, p1) == 0;
	if (y)
		return ccw(p1, p2, p3) == 0;

	return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0
			&& ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<point, point>> v(n);
		for (auto &it : v)
			cin >> it.first >> it.second;
		vector<vector<int>> adj(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (intersect(v[i].first, v[i].second, v[j].first, v[j].second))
					adj[i][j] = 1;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					adj[i][j] |= adj[i][k] && adj[k][j];
		int a, b;
		while (cin >> a >> b, a || b)
			cout << (adj[a - 1][b - 1] ? "CONNECTED" : "NOT CONNECTED") << endl;
		if (t)
			cout << endl;
	}
}
