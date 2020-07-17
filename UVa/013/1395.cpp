#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int oo = 1e5, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

struct DSU {
	vector<int> rank, parent;
	int	forsets;
	DSU(int n) {
		rank = parent = vector<int>(n + 1);
		forsets = n;
		for (int i = 0; i <= n; i++)
			rank[i] = 1, parent[i] = i;
	}
	int find_set(int x) {
		if (x == parent[x])return x;
		return parent[x] = find_set(parent[x]);
	}
	void link(int x, int y) {
		parent[x] = y;
		if (rank[x] == rank[y])rank[y]++;
	}
	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			if (rank[x] > rank[y])swap(x, y);
			link(x, y);
			forsets--;
		}
		return x != y;
	}
	bool same_set(int x, int y) {
		return find_set(x) != find_set(y);
	}
};

struct edge {
	int from, to, weight;
	edge() {}
	edge(int from, int to, int weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return  weight < other.weight;
	}
};

vector<edge> edgeList;
//O(e*log(e))
int MST_Kruskal(int n, int st) {
	DSU uf(n);
	int min = oo, max = 0;
	vector<edge> edges;
	sort(edgeList.begin(), edgeList.end());
	for (int i = st; i < sz(edgeList); i++) {
		edge e = edgeList[i];
		if (uf.union_sets(e.from, e.to)) {
			edges.push_back(e);
		}
	}
	if (edges.size() != n - 1)return oo;
	return edges.back().weight - edges[0].weight;
}

int main() {
	run();
	int n, m;
	while (cin >> n >> m, n || m) {
		edgeList = vector<edge>();
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			edgeList.push_back(edge(u, v, w));
		}
		int mn = oo;
		for (int i = 0; i < sz(edgeList); i++) {
			mn = min(mn, MST_Kruskal(n, i));
		}
		cout << (mn == oo ? -1 : mn) << endl;
	}
}