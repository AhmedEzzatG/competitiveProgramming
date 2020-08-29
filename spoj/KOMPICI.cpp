#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
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
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

const int M = (1 << 10);
int main() {
	run();
	int n;
	cin >> n;
	vector<int> mp(M);
	vector<int> cnt(M);
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		int have = 0;
		while (a) {
			have |= (1 << a % 10);
			a /= 10;
		}
		cnt[have]++;
	}
	for (int have = 0; have < M; have++) {
		for (int i = 1; i < M; i++) {
			if ((i & have) != i)
				continue;
			mp[i] += cnt[have];
		}
	}
	ll ans = 0;
	for (int have = 0; have < M; have++) {
		for (int i = 1; i < M; i++) {
			if ((i & have) != i)
				continue;
			ans += (__builtin_popcount(i) & 1 ? 1LL : -1LL) * cnt[have]
					* (mp[i] - 1);
		}
	}
	cout << ans / 2 << endl;
}
