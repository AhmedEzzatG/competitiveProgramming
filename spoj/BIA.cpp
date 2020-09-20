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
int vis[5001], test_id, cnt;
void dfs(int node) {
	if (vis[node] == test_id)
		return;
	cnt++;
	vis[node] = test_id;
	for (int ch : adj[node])
		dfs(ch);
}
void solve() {
	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> out;
	for (int i = 1; i <= n; i++) {
		vis[i] = ++test_id;
		cnt = 0;
		dfs(1);
		if (cnt != n - 1)
			out.push_back(i);
	}
	cout << sz(out) << endl;
	for (auto &it : out)
		cout << it << ' ';
	cout << endl;
}

int main() {
	run();
	int T = 10;
	while (T--) {
		solve();
	}
}
