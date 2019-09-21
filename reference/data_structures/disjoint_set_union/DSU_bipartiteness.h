#include<bits/stdc++.h>
using namespace std;

class DSU_bipartiteness {
	vector<int> bipartite, rank;
	vector<pair<int, int>> parent;
public:
	DSU_bipartiteness(int n) {
		bipartite = rank = vector<int>(n + 1, 1);
		parent = vector<pair<int, int>>(n + 1);
		for (int i = 0; i <= n; i++)
			parent[i] = { i,0 };
	}
	pair<int, int> find_set(int x) {
		if (x == parent[x].first)return parent[x];
		int parity = parent[x].second;
		parent[x] = find_set(parent[x].first);
		parent[x].second ^= parity;
		return parent[x];
	}
	void union_sets(int x, int y) {
		pair<int, int> p = find_set(x);
		x = p.first;
		int paX = p.second;
		p = find_set(y);
		y = p.first;
		int paY = p.second;
		if (x == y) {
			if (paX == paY)
				bipartite[x] = false;
		}
		else {
			if (rank[x] < rank[y]) swap(x, y);
			parent[y] = { x, paX ^ paY ^ 1 };
			bipartite[x] &= bipartite[y];
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	bool is_bipartite(int x) {
		return bipartite[find_set(x).first];
	}
};
