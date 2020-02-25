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
	int from, to, weight;
	edge() { from = to = weight = 0; }
	edge(int from, int to, int weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return  weight > other.weight;
	}
};
vector<vector<edge>> adj;

int dijkstra(int src, int dest) {
	priority_queue<edge> q;
	vector<int> dis(adj.size(), oo), prev(adj.size(), -1);
	q.push(edge(-1, src, 0));
	dis[src] = 0;
	while (!q.empty()) {
		edge e = q.top(); q.pop();
		if (e.weight > dis[e.to])continue;
		prev[e.to] = e.from;
		for (edge ne : adj[e.to])
			if (dis[ne.to] > dis[e.to] + ne.weight) {
				ne.weight = dis[ne.to] = dis[e.to] + ne.weight;
				q.push(ne);
			}
	}
	return dis[dest];
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		adj = vector<vector<edge>>(n + 1);
		map<string, int> id;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			id[s] = i;
			int m; cin >> m;
			while (m--) {
				int v, c;
				cin >> v >> c;
				adj[i].push_back(edge(i, v, c));
			}
		}
		int m; cin >> m;
		while (m--) {
			string x, y;
			cin >> x >> y;
			cout << dijkstra(id[x], id[y]) << endl;
		}
	}
}
