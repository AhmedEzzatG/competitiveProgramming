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
vector<int> cl;
bool b;
void dfs(int node, bool c) {
	vis[node] = 1;
	cl[node] = c;
	for (int child : adj[node])
		if (cl[child] == -1)
			dfs(child, !c);
		else if (cl[child] == cl[node]) {
			b = 0; return;
		}
}

int main() {
	run();
	int n, m;
	while (cin >> n >> m) {
		b = 1;
		adj = vector<vector<int>>(n);
		cl = vector<int>(n, -1);
		vis = vector<bool>(n);
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i < n; i++)
			if (!vis[i]) dfs(i, 1);
		if (b)cout << "BICOLORABLE.";
		else cout << "NOT BICOLORABLE.";
		cout << endl;
	}
}