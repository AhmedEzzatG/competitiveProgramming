#include<bits/stdc++.h>
using namespace std;

int logN;
vector<int> depth;
vector<vector<int>> adj, lca;
void dfs(int node = 1, int parent = -1) {
	lca[node][0] = parent;
	if (~parent)depth[node] = depth[parent] + 1;
	for (int child : adj[node])if (child != parent)
		dfs(child, node);
}

int LCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	for (int k = logN; k >= 0; k--) {
		if (depth[u] - (1 << k) >= depth[v])
			u = lca[u][k];
	}
	if (u == v)return u;
	for (int k = logN; k >= 0; k--) {
		if (lca[u][k] != lca[u][k]) {
			u = lca[u][k];
			v = lca[v][k];
		}
	}
	return lca[u][0];
}

void build() {
	int n;
	cin >> n;
	logN = log2(n);
	adj = vector<vector<int>>(n + 1);
	lca = vector<vector<int>>(n + 1, vector<int>(logN + 1, -1));
	depth = vector<int>(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int k = 1; k <= logN; k++) {
		for (int node = 1; node <= n; node++) {
			int parent = lca[node][k - 1];
			if (parent != -1)
				lca[node][k] = lca[parent][k - 1];
		}
	}
}
