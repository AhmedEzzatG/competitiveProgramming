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

ll dp[20][1 << 20];
int vis[20][1 << 20], v[20][20], n, test_id;

ll solve(int idx, int mask) {
	if (idx == n)
		return 1;
	ll &rt = dp[idx][mask];
	if (vis[idx][mask] == test_id)
		return rt;
	vis[idx][mask] = test_id;
	rt = 0;
	for (int topic = 0; topic < n; topic++)
		if (!(mask & (1 << topic)) && v[idx][topic])
			rt += solve(idx + 1, mask | (1 << topic));
	return rt;
}
void solve() {
	test_id++;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	cout << solve(0, 0) << endl;
}

int main() {
	run();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
