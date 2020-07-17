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
	//freopen("input.out", "w", stdout);
#else
#endif
}

vector<vector<int>> adj;
vector<pair<int, int>> v;
int mem[1 << 13][13];
int save(int mask, int cur) {
	int& rt = mem[mask][cur];
	if (~rt)return rt;
	rt = -adj[cur][0];
	for (int i = 0; i < sz(v); i++) {
		if (mask & (1 << i))continue;
		int nMask = mask | (1 << i), u = v[i].first, prft = v[i].second;
		rt = max(rt, prft - adj[cur][u] + save(nMask, u));
	}
	return rt;
}

int main() {
	run();
	cout << fixed << setprecision(2);
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n, m;
		cin >> n >> m;
		adj = vector<vector<int>>(n + 1, vector<int>(n + 1, oo));
		for (int i = 0; i <= n; i++) adj[i][i] = 0;
		while (m--) {
			int u, v; double d;
			cin >> u >> v >> d;
			int cost = d * 100 + 1e-3;
			adj[v][u] = adj[u][v] = min(adj[u][v], cost);
		}
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		cin >> m;
		v = vector<pair<int, int>>(m);
		while (m--) {
			double d;
			cin >> v[m].first >> d;
			v[m].second = d * 100 + 1e-3;
		}
		int ans = save(0, 0);
		if (ans <= 0)cout << "Don't leave the house\n";
		else cout << "Daniel can save $" << ans / 100.0 << endl;
	}
}