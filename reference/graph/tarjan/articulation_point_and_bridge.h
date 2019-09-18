#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> articulation_point;
vector<pair<int, int>> bridge;
int timer, cntChild;

// O(n + m)
void tarjan(int node, int par) {
	dfs_num[node] = dfs_low[node] = ++timer;
	for (int child : adj[node])
		if (!dfs_num[child]) {
			if (par == -1)cntChild++;
			tarjan(child, node);
			if (dfs_low[child] >= dfs_num[node])
				articulation_point[node] = 1;
				//can be (dfs_low[child] == dfs_num[child])
			if (dfs_low[child] > dfs_num[node])
				bridge.push_back({ node,child });
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (child != par)
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
}

void articulation_point_and_bridge() {
	timer = 0;
	dfs_num = dfs_low = vector<int>(adj.size());
	articulation_point = vector<bool>(adj.size());
	bridge = vector<pair<int, int>>();
	for (int i = 1; i < adj.size(); i++)
		if (!dfs_num[i]) {
			cntChild = 0;
			tarjan(i, -1);
			articulation_point[i] = cntChild > 1;
		}
}