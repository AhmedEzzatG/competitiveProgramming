#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
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
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

struct edge {
	int from, to, w;
	edge(int from, int to, int w) :
			from(from), to(to), w(w) {
	}
	bool operator<(const edge &o) const {
		return w > o.w;
	}
};

vector<vector<int>> shortest;
vector<vector<edge>> adj;
vector<vector<int>> s_shortest;
void init(int n) {
	shortest = vector<vector<int>>(n, vector<int>(n, INF));
	s_shortest = vector<vector<int>>(n, vector<int>(n, -1));
	adj = vector<vector<edge>>(n);
	for (int i = 0; i < n; i++)
		shortest[i][i] = 0;
}
void dijkstra(int node) {
	priority_queue<edge> q;
	q.push(edge(-1, node, 0));
	while (sz(q)) {
		int cur = q.top().to, w = q.top().w;
		q.pop();
		if (s_shortest[node][cur] != -1)
			continue;
		if (w > shortest[node][cur])
			s_shortest[node][cur] = w;
		for (edge e : adj[cur]) {
			e.w += w;
			q.push(e);
		}
	}
}
int main() {
	run();
	int n, e;
	int I = 1;
	while (cin >> n >> e) {
		cout << "Set #" << I++ << endl;
		init(n);
		while (e--) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back(edge(u, v, w));
			adj[v].push_back(edge(v, u, w));
			shortest[u][v] = shortest[v][u] = w;
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					shortest[i][j] = min(shortest[i][j],
							shortest[i][k] + shortest[k][j]);
		for (int i = 0; i < n; i++)
			dijkstra(i);
		cin >> e;
		while (e--) {
			int u, v;
			cin >> u >> v;
			if (s_shortest[u][v] == -1)
				cout << "?\n";
			else
				cout << s_shortest[u][v] << endl;
		}
	}
}