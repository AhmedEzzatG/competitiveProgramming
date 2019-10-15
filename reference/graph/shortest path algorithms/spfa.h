#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int>> vii;

void SPFA(vector<vii> adjL, int Src, int n, int m) {    // relative to Bellman_ford
	int Max_Path = INT_MAX;
	vector<int> d(n + 1, Max_Path), cnt(n + 1), prev(n + 1, -1);
	vector<bool> inqueue(n + 1);
	queue <int> q;
	q.push(Src);
	d[Src] = 0;
	inqueue[Src] = 1;
	int x;
	bool flag = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inqueue[u] = 0;
		for (auto it : adjL[u]) {
			int v = it.first;
			int cost = it.second;
			if (d[v] > d[u] + cost) {
				d[v] = max(-Max_Path, d[u] + cost);
				prev[v] = u;
				cnt[v]++;
				if (!inqueue[v]) {
					inqueue[v] = 1;
					q.push(v);
				}
				if (cnt[v] > n) {
					x = v;
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			break;
	}
	if (!flag)
		cout << "No negative cycle from " << Src << endl;
	else {
		int y = x;
		for (int i = 0; i < n; i++)
			y = prev[y];
		vector<int> path;
		for (int cur = prev[y]; ; cur = prev[cur]) {
			path.push_back(cur);
			if (cur == y && path.size() > 1)
				break;
		}
		cout << "Negative cycle: ";
		for (auto it : path)
			cout << it << ' ';
		cout << endl;
	}
}
