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
int b;
vector<vector<int>> adj;
vector<pair<int, int>> v;
bool getBit(int n, int idx) { return ((n >> idx) & 1); }
int setBit(int n, int idx) { return (n | (1 << idx)); }
ll mem[109][1 << 12];
ll dp(int last, int mask) {
	if (mask == (1 << sz(v)) - 1)return adj[last][b];
	ll& rt = mem[last][mask];
	if (~rt)return rt;
	rt = oo;
	for (int i = 0; i < sz(v); i++) {
		if (getBit(mask, i))continue;
		int nMask = setBit(mask, i);
		rt = min(rt, adj[last][v[i].first] +
			adj[v[i].first][v[i].second] + dp(v[i].second, nMask));
	}
	return rt;
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m >> b;
		adj = vector<vector<int>>(n + 1, vector<int>(n + 1, oo));
		for (int i = 1; i <= n; i++)adj[i][i] = 0;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[v][u] = adj[u][v] = min(adj[u][v], w);
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		int z; cin >> z;
		v.clear();
		while (z--) {
			int a, b, c;
			cin >> a >> b >> c;
			while (c--) v.push_back({ a,b });
		}
		clr(mem, -1);
		cout << dp(b, 0) << endl;
	}
}
