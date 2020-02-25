#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define RT(v) return cout<<v,0
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int oo = INT_MAX, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-5;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}

vector<vector<int>> adj;
vector<bool> vis;
vector<int> topsort;
void dfs(int node) {
	if (vis[node])return;
	vis[node] = true;
	for (int child : adj[node])
		dfs(child);
	topsort.push_back(node);
}
int main() {
	run();
	int n, k;
	cin >> n >> k;
	adj.resize(n + 1); vis.resize(n + 1);
	for (int i = 1; i <= k; i++) {
		int m; cin >> m;
		while (m--) {
			int x; cin >> x;
			adj[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) dfs(i);
	topsort.push_back(0);
	reverse(all(topsort));
	vector<int> par(n + 1);
	for (int i = 1; i <= n; i++) {
		par[topsort[i]] = topsort[i - 1];
	}
	for (int i = 1; i <= n; i++)
		cout << par[i] << endl;
}
