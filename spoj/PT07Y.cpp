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
vector<vector<int>> adj;
bitset<10001> vis;
void dfs(int node) {
	vis[node] = 1;
	for (int child : adj[node]) {
		if (!vis[child])dfs(child);
	}
}
int main() {
	run();
	int n, e;
	cin >> n >> e;
	if (e != n - 1)RT("NO");
	adj = vector<vector<int>>(n + 1);
	while (e--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 2; i <= n; i++)
		if (!vis[i])RT("NO");
	RT("YES");
}
