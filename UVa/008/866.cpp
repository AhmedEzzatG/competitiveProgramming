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
#define vec(a,b)  ((b)-(a))
#define cp(a,b)   ( (conj(a)*(b)).imag() )
bool intersectSegments(point a, point b, point c, point d) {
	double d1 = cp(vec(b, a), vec(c, d)), d2 = cp(vec(c, a), vec(c, d)), d3 =
			cp(vec(b, a), vec(c, a));
	if (fabs(d1) < EPS)
		return false;

	double t1 = d2 / d1, t2 = d3 / d1;

	if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;
	return true;
}

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<point>> v(n);
		for (auto &it : v) {
			it = vector<point>(2);
			cin >> it[0] >> it[1];
		}
		int cnt = n;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (intersectSegments(v[i][0], v[i][1], v[j][0], v[j][1]))
					cnt += 2;
			}
		}
		cout << cnt << endl;
		if (t)
			cout << endl;
	}
}