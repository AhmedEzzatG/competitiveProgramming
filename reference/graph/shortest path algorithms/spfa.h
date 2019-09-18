#include<bits/stdc++.h>
#include"..\..\data_structures\edge.h"
using namespace std;
#define oo 0x3f3f3f3fLL

vector<vector<edge>> adj;

bool spfa(int n, int src, int dest = -1) {
	vector<int> dis(n + 1, oo), prev(n + 1, -1), cntVis(n + 1);
	vector<bool> inQueue(n + 1);
	queue<int> q; q.push(src);
	inQueue[src] = 1;
	dis[src] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		inQueue[cur] = 0;
		for (edge it : adj[cur]) {
			int to = it.to, w = it.weight;
			if (dis[to] > dis[cur] + w) {
				dis[to] = dis[cur] + w;
				prev[to] = cur;
				cntVis[to]++;
				if (!inQueue[to]) {
					q.push(to); inQueue[to] = 1;
				}
				if (cntVis[to] > n) return false;
			}
		}
	}
	return true;
}