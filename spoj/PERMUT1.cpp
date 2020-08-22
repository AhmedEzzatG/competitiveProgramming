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
void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<ll>> dp(1 << n, vector<ll>(k + 1));
	dp[0][0] = 1;
	for (int mask = 0; mask < (1 << n); mask++)
		for (int cnt = 0; cnt <= k; cnt++) {
			int cntG = 0;
			for (int cur = n - 1; cur >= 0 && cnt + cntG <= k; cur--) {
				if (mask & (1 << cur)) {
					cntG++;
					continue;
				}
				dp[mask | (1 << cur)][cnt + cntG] += dp[mask][cnt];
			}

		}
	cout << dp[(1 << n) - 1][k] << endl;
}

int main() {
	run();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
