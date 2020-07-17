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

map<int, vector<int>> adj;
map<int, int> in;
map<int, int> vis;
bool dfs(int node) {
	vis[node] = 1;
	bool b = 1;
	for (int child : adj[node]) {
		if (!vis[child]) b &= dfs(child);
		else return 0;
	}
	return b;
}
int main() {
	run();
	int u, v, I = 1;
	while (cin >> u >> v, u >= 0 || v >= 0) {
		cout << "Case " << I++;
		if (u == 0 && v == 0) {
			cout << " is a tree.\n";
			continue;
		}
		adj.clear(); in.clear(); vis.clear();
		in[v]++;
		in[u]++; in[u]--;
		adj[u].push_back(v);
		while (cin >> u >> v, u || v) {
			in[u]++; in[u]--;
			in[v]++;
			adj[u].push_back(v);
		}
		bool f = 0;
		int root = -1;
		for (auto it : in) if (it.second == 0) {
			if (!f)f = 1, root = it.first;
			else { f = 0; break; }
		}
		if (!f) {
			cout << " is not a tree.\n";
			continue;
		}
		if (dfs(root) && sz(vis) == sz(in))
			cout << " is a tree.\n";
		else cout << " is not a tree.\n";
	}
}