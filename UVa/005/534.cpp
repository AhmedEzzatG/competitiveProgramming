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
	int from, to;
	double weight;
	edge() {}
	edge(int from, int to, double weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return  weight < other.weight;
	}
};

vector<edge> edgeList;
double miniMax(int src, int dest, int n) {
	double max = -oo;
	DSU uf(n);
	sort(edgeList.begin(), edgeList.end());
	for (auto e : edgeList) {
		if (uf.same_set(src, dest))return max;
		uf.union_sets(e.from, e.to);
		max = e.weight;
	}
	return max;
}

int main() {
	run();
	int n;
	int I = 1;
	while (cin >> n, n) {
		cout << "Scenario #" << I++ << "\nFrog Distance = ";
		vector<pair<double, double>> v(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i].first >> v[i].second;
		edgeList = vector<edge>();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				double dis = hypot(abs(v[i].first - v[j].first), abs(v[i].second - v[j].second));
				edgeList.push_back(edge(i, j, dis));
			}
		cout << fixed << setprecision(3) << miniMax(1, 2, n) << endl << endl;
	}
}
