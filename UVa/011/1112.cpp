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
//	freopen("output.out", "w", stdout);
#else
#endif
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, e, ti, m;
		cin >> n >> e >> ti >> m;
		vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, (ll)oo * oo));
		for (int i = 1; i <= n; i++)adj[i][i] = 0;
		while (m--) {
			int u, v;
			ll w;
			cin >> u >> v >> w;
			adj[u][v] = min(adj[u][v], w);
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += adj[i][e] <= ti;
		cout << cnt << endl;
		if (t) cout << endl;
	}
}