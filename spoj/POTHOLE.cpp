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
const int N = 201;
int cap[N][N], vis[N], n;
bool getPath(int src, int sink, vector<int> &path) {
	path.push_back(src);
	if (src == sink)
		return true;
	vis[src] = 1;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && cap[src][i])
			if (getPath(i, sink, path))
				return true;
	path.pop_back();
	return false;
}

int maxFlow(int src, int sink) {
	int total_flow = 0;
	while (true) {
		memset(vis, 0, sizeof(vis));
		vector<int> path;
		if (getPath(src, sink, path)) {
			total_flow++;
			for (int i = 1; i < sz(path); i++) {
				cap[path[i - 1]][path[i]]--;
				cap[path[i]][path[i - 1]]++;
			}
		} else
			break;
	}
	return total_flow;
}

void solve() {
	memset(cap, 0, sizeof(cap));
	cin >> n;
	for (int i = 1; i < n; i++) {
		int m;
		cin >> m;
		while (m--) {
			int u;
			cin >> u;
			cap[i][u] = (i == 1 || u == n ? 1 : n);
		}
	}
	cout << maxFlow(1, n) << endl;
}

int main() {
	run();
	int T;
	cin >> T;
	while (T--)
		solve();
}
