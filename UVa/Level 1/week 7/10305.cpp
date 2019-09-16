#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
#define oo INT_MAX
int dr[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[] { 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif
}

vector<vector<int>> adj;
vector<int> topsort;
bool vis[110];

void dfs(int node) {
	if (vis[node])
		return;
	vis[node] = true;
	for (int child : adj[node])
		dfs(child);
	topsort.push_back(node);
}
int main() {
	run();
	int n, m;
	while (cin >> n >> m, (n || m)) {
		adj.clear();
		adj.resize(n + 1);
		clr(vis, 0);
		topsort.clear();
		while (m--) {
			int x, y;
			cin >> x >> y;
			adj[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			dfs(i);
		}
		cout << topsort[0];
		for (int i = 1; i < n; i++)
			cout << ' ' << topsort[i];
		cout << endl;
	}
}
