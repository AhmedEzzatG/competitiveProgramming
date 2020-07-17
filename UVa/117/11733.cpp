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
#else
#endif
}

struct edge {
	int from, to;
	double weight;
	edge() {}
	edge(int from, int to, double weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return weight < other.weight;
	}
};
vector<edge> edgeList;

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
	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			if (rank[x] > rank[y])swap(x, y);
			parent[x] = y;
			size[y] += size[x];
			if (rank[x] == rank[y])rank[y]++;
			forsets--;
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

pair<ll, int> MST_Kruskal(int n, ll a) {
	DSU uf(n);
	ll mstCost = 0;
	sort(edgeList.begin(), edgeList.end());
	for (auto e : edgeList)
		if (uf.union_sets(e.from, e.to)) {
			if (e.weight < a) mstCost += e.weight;
			else { uf.forsets++; break; }
		}
	return { mstCost + uf.forsets * a,uf.forsets };
}

int main() {
	run();
	int t;
	while (cin >> t) {
		for (int I = 1; I <= t; I++) {
			edgeList = vector<edge>();
			int n, m;
			ll c;
			cin >> n >> m >> c;
			while (m--) {
				int u, v, w;
				cin >> u >> v >> w;
				edgeList.push_back(edge(u, v, w));
			}
			pair<ll, int> ans = MST_Kruskal(n, c);
			cout << "Case #" << I << ": " << ans.first << ' ' << ans.second << endl;
		}
	}
}