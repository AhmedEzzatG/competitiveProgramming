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
int dcmp(double x, double y) {
	if (fabs(x - y) < 1e-3)
		return 0;
	return (x < y ? -1 : 1);
}

int cnt;
struct rectangle {
	double x1, y1, x2, y2;
	int idx;
	void read() {
		cin >> x1 >> y1 >> x2 >> y2;
		idx = ++cnt;
		if (dcmp(x1, x2) > 0)
			swap(x1, x2);
		if (dcmp(y1, y2) > 0)
			swap(y1, y2);
	}
	bool in(double x, double y) {
		return dcmp(x1, x) <= 0 && dcmp(x, x2) <= 0 && dcmp(y1, y) <= 0
				&& dcmp(y, y2) <= 0;
	}
};

struct circle {
	double x, y, r;
	int idx;
	void read() {
		cin >> x >> y >> r;
		idx = ++cnt;
	}
	bool in(double x, double y) {
		double xx = fabs(x - this->x), yy = fabs(y - this->y);
		return dcmp(hypot(xx, yy), r) <= 0;
	}
};

int main() {
	run();
	char ch;
	vector<rectangle> r;
	vector<circle> c;
	while (cin >> ch, ch != '*') {
		if (ch == 'r') {
			r.push_back(rectangle());
			r.back().read();
		} else {
			c.push_back(circle());
			c.back().read();
		}
	}
	double x, y;
	int I = 0;
	while (cin >> x >> y, x != 9999.9 && y != 9999.9) {
		++I;
		vector<int> ans;
		for (auto &it : r)
			if (it.in(x, y))
				ans.push_back(it.idx);
		for (auto &it : c)
			if (it.in(x, y))
				ans.push_back(it.idx);
		sort(all(ans));
		for (auto &it : ans)
			cout << "Point " << I << " is contained in figure " << it << endl;
		if (ans.empty())
			cout << "Point " << I << " is not contained in any figure\n";
	}
}
