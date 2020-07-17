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
vector<bool> vis;
vector<vector<int>> adj;
int dfs(int node) {
	if (vis[node])return 0;
	vis[node] = 1;
	int c = 1;
	for (int child : adj[node])
		c += dfs(child);
	return c;
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, m, l;
		cin >> n >> m >> l;
		adj = vector<vector<int>>(n + 1);
		vis = vector<bool>(n + 1);
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		int c = 0;
		while (l--) {
			int x; cin >> x;
			c+= dfs(x);
		}
		cout << c;
		cout << endl;
	}
}