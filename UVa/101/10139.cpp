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

vector<pair<int, int>> factors(int n) {
	vector<pair<int, int>> v;
	if (n < 2)
		return v;
	if (n % 2 == 0) {
		v.push_back( { 2, 0 });
		while (n % 2 == 0)
			v.back().second++, n /= 2;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			v.push_back( { i, 0 });
			while (n % i == 0)
				v.back().second++, n /= i;
		}
	}
	if (n > 1)
		v.push_back( { n, 1 });
	return v;
}

int main() {
	run();
	int n, m;
	while (cin >> n >> m) {
		vector<pair<int, int>> v = factors(m);
		bool valid = true;
		for (auto it : v) {
			for (ll x = it.first; x <= n + 1 && it.second > 0; x *= it.first) {
				it.second -= (n + (n == 0)) / x;
			}
			if (it.second > 0) {
				valid = false;
				break;
			}
		}
		if (valid)
			cout << m << " divides " << n << "!\n";
		else
			cout << m << " does not divide " << n << "!\n";
	}
}
