#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

struct edge {
	int from, to, weight;
	edge() {
		from = to = weight = 0;
	}
	edge(int from, int to, int weight) :
			from(from), to(to), weight(weight) {
	}
	bool operator <(const edge &other) const {
		return weight < other.weight;
	}
};

vector<edge> edgeList;

struct DSU {
	vector<int> rank, parent, size;
	int forsets;
	DSU(int n) {
		size = rank = parent = vector<int>(n + 1, 1);
		forsets = n;
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}
	void link(int par, int node) {
		parent[node] = par;
		size[par] += size[node];
		if (rank[par] == rank[node])
			rank[par]++;
		forsets--;
	}
	bool union_sets(int v, int u) {
		v = find_set(v), u = find_set(u);
		if (v != u) {
			if (rank[v] < rank[u])
				swap(v, u);
			link(v, u);
		}
		return v != u;
	}
	bool same_set(int v, int u) {
		return find_set(v) == find_set(u);
	}
	int size_set(int v) {
		return size[find_set(v)];
	}
};

ll SMST_Kruskal(int n) {
	DSU uf(n);
	sort(edgeList.begin(), edgeList.end());
	vector<edge> take, leave;
	ll mstCost = 0;
	for (auto e : edgeList)
		if (uf.union_sets(e.from, e.to)) {
			mstCost += e.weight;
			take.push_back(e);
		} else
			leave.push_back(e);
	if (uf.forsets != 1)
		return -1;
	ll ans = INF, mnCost = mstCost;
	for (int i = 0; i < take.size(); i++) {
		uf = DSU(n);
		mstCost = 0;
		for (int j = 0; j < take.size(); j++) {
			if (i == j)
				continue;
			uf.union_sets(take[j].from, take[j].to);
			mstCost += take[j].weight;
		}
		for (edge e : leave) {
			if (uf.union_sets(e.from, e.to)) {
				mstCost += e.weight;
				break;
			}
		}
		if (uf.forsets == 1 && mstCost < ans)
			ans = mstCost;
	}
	return ans;
}

int main() {
	run();
	int t;
	cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case #" << I << " : ";
		int n, e;
		cin >> n >> e;
		edgeList = vector<edge>(e);
		for (auto &it : edgeList)
			cin >> it.from >> it.to >> it.weight;
		ll rt = SMST_Kruskal(n);
		if (rt == -1)
			cout << "No way\n";
		else if (rt == INF)
			cout << "No second way\n";
		else
			cout << rt << endl;
	}
}
