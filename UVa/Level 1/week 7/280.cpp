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
#define RT(v) return cout<<v,0
#define watch(x) cout << (#x) << " = " << x << endl
#define oo INT_MIN
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}

int n;
vector<vector<int>> adj;
vector<int> vis;
void dfs(int node, int x) {
	for (auto child : adj[node]) {
		if (vis[child] != x) {
			vis[child] = x;
			dfs(child, x);
		}
	}
}

int main() {
	run();
	int I = 0;
	while (cin >> n, n) {
		vis.clear(); adj.clear();
		vis.resize(n + 2); adj.resize(n + 2);
		int u;
		while (cin >> u, u) {
			int x;
			while (cin >> x, x)
				adj[u].push_back(x);
		}
		cin >> u;
		while (u--) {
			I++;
			int x; cin >> x;
			dfs(x, I);
			queue<int> q;
			for (int i = 1; i <= n; i++) {
				if (vis[i] != I)
					q.push(i);
			}
			cout << sz(q);
			while (!q.empty()) {
				cout << ' ' << q.front();
				q.pop();
			}
			cout << endl;
		}
	}
}
