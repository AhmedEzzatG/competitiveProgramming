#include<bits/stdc++.h>
#include"..\edge.h"
using namespace std;
vector<vector<edge>> adj;

//O(n*log(m))
void dijkstra(int src, int dest = -1) {
	priority_queue<edge> q;
	vector<int> dis(adj.size(), INT_MAX), prev(adj.size(), -1);
	q.push(edge(-1, src, 0));
	dis[src] = 0;
	while (!q.empty()) {
		edge e = q.top(); q.pop();
		if (e.weight > dis[e.to])continue;
		prev[e.to] = e.from;
		for (edge ne : adj[e.to])
			if (dis[ne.to] > dis[e.to] + ne.weight) {
				ne.weight = dis[ne.to] = dis[e.to] + ne.weight;
				q.push(ne);
			}
	}
	vector<int> path;
	while (dest != -1) {
		path.push_back(dest);
		dest = prev[dest];
	}
	reverse(path.begin(), path.end());
}