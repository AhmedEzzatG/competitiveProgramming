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
vector<vector<int>> adjMat, path;
void dijkstra(int src) {
	priority_queue<edge> q;
	vector<int>& dis = adjMat[src];
	dis = vector<int>(adj.size(), oo);
	vector<int>& prev = path[src];
	prev = vector<int>(adj.size(), -1);
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
}

void buildPath(int src, int dest) {
	if (dest == -1) return;
	if (path[src][dest] != -1) {
		buildPath(src, path[src][dest]);
		cout << ' ' << dest;
	}
	else cout << dest;
}
int main() {
	run();
	int n, s, e;
	bool b = 0;
	while (cin >> n >> s >> e) {
		if (b)cout << endl;
		b = 1;
		adj = vector<vector<edge>>(n + 1);
		path = adjMat = vector<vector<int>>(n + 1);
		int m; cin >> m;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].emplace_back(u, v, w);
			adj[v].emplace_back(v, u, w);
		}
		for (int i = 1; i <= n; i++) dijkstra(i);
		cin >> m;
		int mn = adjMat[s][e];
		pair<int, int> p = { -1,-1 };
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			int val = adjMat[s][u] + adjMat[v][e] + w;
			if (val <= mn) p = { u,v }, mn = val;
			val = adjMat[s][v] + adjMat[u][e] + w;
			if (val <= mn) p = { v,u }, mn = val;
		}
		if (p.first == -1) {
			buildPath(s, e);
			cout << endl;
			cout << "Ticket Not Used\n";
		}
		else {
			buildPath(s, p.first);
			cout << ' ';
			buildPath(p.second, e);
			cout << endl;
			cout << p.first << endl;
		}
		cout << mn << endl;
	}
}