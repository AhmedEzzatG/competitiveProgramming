#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}
vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<pair<int, int>> bridge;
int timer;
void tarjan(int node, int par) {
	dfs_num[node] = dfs_low[node] = ++timer;
	for (int child : adj[node])
		if (!dfs_num[child]) {
			tarjan(child, node);
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
			if (dfs_low[child] > dfs_num[node])
				bridge.push_back({ min(node,child),max(node,child) });
		}
		else if (child != par)
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
}


int main() {
	run();
	int n;
	while (cin >> n) {
		adj = vector<vector<int>>(n);
		dfs_low = dfs_num = vector<int>(n);
		bridge = vector<pair<int, int>>();
		for (int i = 0; i < n; i++) {
			int u, m; char ch;
			cin >> u >> ch >> m >> ch;
			while (m--) {
				int v; cin >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		timer = 0;
		for (int i = 0; i < n; i++)
			if (!dfs_num[i])tarjan(i, -1);
		sort(all(bridge));
		cout << sz(bridge) << " critical links\n";
		for (auto it : bridge)
			cout << it.first << " - " << it.second << endl;
		cout << endl;
	}
}