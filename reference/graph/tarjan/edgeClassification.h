#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> start, finish;
int timer;

void dfsEdgeClassification(int node) {
	start[node] = timer++;
	for (int child : adj[node]) {
		if (start[child] == -1)
			dfsEdgeClassification(child);
		else {
			if (finish[child] == -1); // Back Edge
			else if (start[node] < start[child]); // Forward Edge
			else; // Cross Edge
		}
	}
	finish[node] = timer++;
}