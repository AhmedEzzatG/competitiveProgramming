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

double MST_Kruskal(int n) {
	DSU uf(n);
	double mstCost = 0;
	sort(edgeList.begin(), edgeList.end());
	for (auto e : edgeList)
		if (uf.union_sets(e.from, e.to))
			mstCost += e.weight;
	return mstCost;
}

int main() {
	run();
	double d;
	while (cin >> d) {
		edgeList = vector<edge>();
		int n; cin >> n;
		map<string, int> id;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			id[s] = i;
		}
		int m; cin >> m;
		while (m--) {
			string x, y; double w;
			cin >> x >> y >> w;
			edgeList.push_back(edge(id[x], id[y], w));
		}
		double mst = MST_Kruskal(n);
		cout << fixed << setprecision(1);
		if (fabs(mst - d) > 1e-2 && mst > d)cout << "Not enough cable\n";
		else cout << "Need " << mst << " miles of cable\n";
	}
}