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
	//freopen("output.out", "w", stdout);
#else
#endif
}
vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> art_point;
int timer, cntChild;
void tarjan(int node, int par) {
	dfs_num[node] = dfs_low[node] = ++timer;
	for (int child : adj[node])
		if (!dfs_num[child]) {
			if (par == -1)cntChild++;
			tarjan(child, node);
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
			if (dfs_low[child] >= dfs_num[node])
				art_point[node] = 1;
		}
		else if (child != par)
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
}


int main() {
	run();
	int n, m;
	while (cin >> n >> m, n || m) {
		adj = vector<vector<int>>(n + 1);
		dfs_low = dfs_num = vector<int>(n + 1);
		art_point = vector<bool>(n + 1);
		timer = 0;
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			if (!dfs_num[i]) {
				cntChild = 0;
				tarjan(i, -1);
				art_point[i] = cntChild > 1;
			}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (art_point[i])cnt++;
		cout << cnt << endl;
	}
}
