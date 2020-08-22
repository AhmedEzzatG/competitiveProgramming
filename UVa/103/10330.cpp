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

const int N = 205;
int cap[N][N];
int getPath(int src, int sink, vector<int> &path) {
	vector<int> dis(N, 0), prev(N, -1);
	priority_queue<pair<int, int>> q;
	dis[src] = INF;
	q.push( { dis[src], src });
	while (sz(q)) {
		int cur = q.top().second, w = q.top().first;
		q.pop();
		if (w < dis[cur])
			continue;
		if (cur == sink)
			break;
		for (int i = 1; i < N; i++)
			if (cap[cur][i] > 0 && dis[i] < min(w, cap[cur][i])) {
				prev[i] = cur;
				dis[i] = min(w, cap[cur][i]);
				q.push( { dis[i], i });
			}
	}
	int flow = dis[sink];
	if (flow) {
		while (sink != -1) {
			path.push_back(sink);
			sink = prev[sink];
		}
		reverse(all(path));
	}
	return flow;
}

int maxFlow(int src, int sink) {
	int total_flow = 0;
	while (true) {
		vector<int> path;
		int flow = getPath(src, sink, path);
		if (flow == 0)
			break;
		total_flow += flow;
		for (int i = 1; i < sz(path); i++) {
			cap[path[i - 1]][path[i]] -= flow;
			cap[path[i]][path[i - 1]] += flow;
		}
	}
	return total_flow;
}
int main() {
	run();
	int n;
	while (cin >> n) {
		memset(cap, 0, sizeof cap);
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			cap[i][n + i] = v[i];
		}
		int m;
		cin >> m;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			cap[u + n][v] = w;
		}
		int src = 2 * n + 1, sink = 2 * n + 2;
		int b, d;
		cin >> b >> d;
		while (b--) {
			int u;
			cin >> u;
			cap[src][u] = INF;
		}
		while (d--) {
			int u;
			cin >> u;
			cap[u + n][sink] = INF;
		}
		cout << maxFlow(src, sink) << endl;

	}
}