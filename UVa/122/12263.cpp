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
const int N = 509;
vector<vector<int>> adj;
vector<int> top;
bool vis[N], inStack[N], cycle;
void dfs(int node) {
	vis[node] = inStack[node] = true;
	for (int ch : adj[node]) {
		if (!vis[ch])
			dfs(ch);
		else if (inStack[ch]) {
			cycle = true;
			break;
		}
	}
	inStack[node] = false;
	top.push_back(node);
}

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		int n;
		cin >> n;
		vector<int> idx(n + 1);
		adj = vector<vector<int>>(n + 1);
		cycle = false;
		top.clear();
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			idx[a] = i;
		}
		int m;
		cin >> m;
		set<pair<int, int>> edges;
		while (m--) {
			int a, b;
			cin >> a >> b;
			edges.insert( { a, b });
			edges.insert( { b, a });
			if (idx[a] < idx[b])
				adj[a].push_back(b);
			else
				adj[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (edges.count( { i, j }))
					continue;
				if (idx[i] > idx[j])
					adj[i].push_back(j);
				else
					adj[j].push_back(i);
			}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		if (cycle)
			cout << "IMPOSSIBLE\n";
		else {
			for (int i = 0; i < n; i++)
				cout << top[i] << " \n"[i + 1 == n];
		}
	}
}
