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
vector<vector<pair<int, int>>> adj;
int bfs(int node, bool b = 0) {
	queue<int> q;
	vector<int> dep(sz(adj), oo);
	q.push(node);
	dep[node] = 0;
	int cur = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (auto it : adj[cur])
			if (dep[it.first] > dep[cur] + it.second) {
				q.push(it.first);
				dep[it.first] = dep[cur] + it.second;
			}
	}
	for (int i = 1; i < sz(adj); i++)
		if (dep[i] > dep[cur])cur = i;

	if (b)return dep[cur];
	return cur;
}
pair<int, int> p = { -1,-1 };
void dfs(int node, int par, int lvl) {
	if (lvl > p.second)p = make_pair(node, lvl);
	for (auto it : adj[node])
		if (it.first != par) dfs(it.first, node, lvl + it.second);
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		adj = vector<vector<pair<int, int>>>(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ v,w });
			adj[v].push_back({ u,w });
		}
		dfs(1, -1, 0);
		int u = p.first;
		p = { -1,-1 };
		dfs(u, -1, 0);
		cout << p.second << endl;
		p = { -1,-1 };
	}
}
