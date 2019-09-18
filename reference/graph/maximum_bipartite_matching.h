#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> adjMat;
vector<int> rowAssign, colAssign;
vector<bool> vis;
bool canMatch(int i) {
	for (int j = 1; j < adjMat[i].size(); j++)
		if (adjMat[i][j] && !vis[j]) {
			vis[j] = 1;
			if (colAssign[j] == -1 || canMatch(colAssign[j])) {
				colAssign[j] = i; rowAssign[i] = j;
				return true;
			}
		}
	return false;
}

// O(rows * E)
void maximum_bipartite_matching() {
	vector<pair<int, int>> matches;
	int maxFlow = 0, rows = adjMat.size(), cols = adjMat[0].size();
	rowAssign = vector<int>(rows, -1);
	colAssign = vector<int>(cols, -1);
	for (int i = 1; i < rows; i++) {
		vis = vector<bool>(cols);
		if (canMatch(i))maxFlow++;
	}
	for (int j = 1; j < cols; j++) if (~colAssign[j])
		matches.push_back({ colAssign[j],j });
}