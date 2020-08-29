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

vector<vector<int>> adj;
int p = 1, mx = 0;
void dfs(int node, int par, int dep) {
	if (dep > mx)
		p = node, mx = dep;
	for (int ch : adj[node])
		if (ch != par)
			dfs(ch, node, dep + 1);
}
void solve() {
	int n;
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		while (m--) {
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
	}
	p = 1, mx = 0;
	dfs(1, -1, 0);
	dfs(p, -1, 0);
	cout << 2 * (n - 1) - mx << endl;
}
int main() {
	run();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}