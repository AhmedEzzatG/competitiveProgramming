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
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
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
	vector<int> rank, parent, size;
	int	forsets;
	DSU(int n) {
		size = rank = parent = vector<int>(n + 1);
		forsets = n;
		for (int i = 0; i <= n; i++)
			size[i] = rank[i] = 1, parent[i] = i;
	}
	int find_set(int x) {
		if (x == parent[x])return x;
		return parent[x] = find_set(parent[x]);
	}
	void link(int x, int y) {
		parent[x] = y;
		size[y] += size[x];
		if (rank[x] == rank[y])rank[y]++;
		forsets--;
	}
	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			if (rank[x] > rank[y])swap(x, y);
			link(x, y);
		}
		return x != y;
	}
	bool same_set(int x, int y) {
		return find_set(x) == find_set(y);
	}
	int size_set(int x) {
		return size[find_set(x)];
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

int MST_Kruskal(int n) {
	DSU uf(n);
	sort(edgeList.rbegin(), edgeList.rend());
	int mstCost = 0;
	for (auto e : edgeList)
		if (uf.same_set(e.from, e.to))
			mstCost += e.weight;
		else uf.union_sets(e.from, e.to);
	return mstCost;
}

int main() {
	run();
	int t;
	while (cin >> t, t) {
		while (t--) {
			int n, m;
			cin >> n >> m;
			edgeList = vector<edge>();
			while (m--) {
				int u, v, w;
				cin >> u >> v >> w;
				edgeList.push_back(edge(u, v, w));
			}
			cout << MST_Kruskal(n) << endl;
		}
	}
}