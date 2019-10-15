#include"tarjan/strongly_connected_component.h"

int n;
int Not(int x) {
	return(x > n ? x - n : x + n);
}

void addEdge(int a, int b) {
	adj[Not(a)].push_back(b);
	adj[Not(b)].push_back(a);
}

bool _2SAT(vector<int>& value) {
	SCC();
	for (int i = 1; i <= n; i++)
		if (compId[i] == compId[Not(i)])
			return false;
	vector<int> assign(scc.size(), -1);
	for (int i = 0; i < scc.size(); i++) if (assign[i] == -1) {
		assign[i] = true;
		assign[compId[Not(scc[i].back())]] = false;
	}
	for (int i = 1; i <= n; i++)value[i] = assign[compId[i]];
	return true;
}