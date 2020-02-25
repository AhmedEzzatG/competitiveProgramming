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

ll power(ll x, ll y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	ll r = power(x, y >> 1);
	return r * r * power(x, y & 1);
}

bool solve(ll x, int p) {
	if (x < 0) {
		if (p % 2 == 0)
			return false;
		x *= -1;
	}
	ll b = exp(log(x) / p);
	for (ll i = b - 1; i <= b + 1; i++)
		if (power(i, p) == x)
			return true;
	return false;
}

int main() {
	run();
	ll x;
	while (cin >> x, x) {
		int mx = 1;
		for (int p = 2; p <= 32; p++)
			if (solve(x, p)) {
				mx = p;
			}
		cout << mx << endl;
	}
}
