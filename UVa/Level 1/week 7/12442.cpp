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
int dr[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}
int n;
vector<vector<int>> adj;
int vis[50009];
int dfs(int node, int x) {
	if (vis[node] == x)return 0;
	vis[node] = x;
	int cnt = 1;
	for (auto child : adj[node]) {
		if (vis[child] != x)
			cnt += dfs(child, x);
	}
	return cnt;
}

int solve() {
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int c = dfs(i, i);
			if (cnt < c)cnt = c, ans = i;
		}
	}
	return ans;
}
int main() {
	run();
	int t;
	cin >> t;
	for (int I = 1; I <= t; I++) {
		cin >> n;
		adj.resize(n + 2);
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
		cout << "Case " << I << ": " << solve() << endl;
		clr(vis, 0);
		adj.clear();
	}
}
