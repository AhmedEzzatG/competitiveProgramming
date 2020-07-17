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
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}

struct edge {
	int from, to, weight;
	edge() { from = to = weight = 0; }
	edge(int from, int to, int weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return  weight < other.weight;
	}
};

vector<vector<edge>> adj;
vector<edge> edgeList;

bool bfs(int node, int dest) {
	bitset<200> vis;
	queue<int> q; q.push(node);
	vis[node] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (edge e : adj[cur])if (!vis[e.to]) {
			q.push(e.to); vis[e.to] = true;
			if (e.to == dest)return true;
		}
	}
	return false;
}

bool bellmanford(int n) {
	vector<int> dis(n + 1, -oo), prev(n + 1, -1);
	dis[1] = 100;
	int last = -1, tmp = n + 100;
	while (tmp--) {
		last = -1;
		for (edge e : edgeList) if (dis[e.from] > 0 && dis[e.to] < dis[e.from] + e.weight) {
			dis[e.to] = dis[e.from] + e.weight;
			if (e.to == n && dis[e.to] > 0)return true;
			prev[e.to] = e.from;
			last = e.to;
		}
		if (last == -1)break;
	}
	if (last == -1) return dis[n] > 0;
	for (int i = 0; i < n; i++) last = prev[last];
	return bfs(last, n);
}

int main() {
	run();
	int n;
	while (cin >> n, ~n) {
		edgeList = vector<edge>();
		adj = vector<vector<edge>>(n + 1);
		vector<set<int>> connected(n + 1);
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) {
			int m;
			cin >> v[i] >> m;
			while (m--) {
				int x; cin >> x;
				connected[i].insert(x);
			}
		}
		for (int i = 1; i <= n; i++) for (int x : connected[i]) {
			edgeList.push_back(edge(i, x, v[x]));
			adj[i].push_back(edge(i, x, v[x]));
		}
		cout << (bellmanford(n) ? "winnable" : "hopeless") << endl;
	}
}