#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> adjMat;
vector<vector<int>> adj;
vector<int> rowAssign, colAssign, vis;
int test_id;
bool canMatch(int i) {
	for (int j : adj[i]) if (vis[j] != test_id) {
		vis[j] = test_id;
		if (colAssign[j] == -1 || canMatch(colAssign[j])) {
			colAssign[j] = i; rowAssign[i] = j;
			return true;
		}
	}
	return false;
}

// O(rows * E)
int maximum_bipartite_matching(int rows, int cols) {
	int maxFlow = 0;
	rowAssign = vector<int>(rows, -1);
	colAssign = vector<int>(cols, -1);
	vis = vector<int>(cols);
	for (int i = 1; i < rows; i++) {
		test_id++;
		if (canMatch(i))maxFlow++;
	}
	vector<pair<int, int>> matches;
	for (int j = 1; j < cols; j++) if (~colAssign[j])
		matches.push_back({ colAssign[j],j });
	return maxFlow;
}
