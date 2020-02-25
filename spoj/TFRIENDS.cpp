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
vector<int> dfs_num, dfs_low;
vector<bool> inStack;
stack<int> stk;
int timer, scc;
void tarjan(int node) {
	dfs_num[node] = dfs_low[node] = ++timer;
	stk.push(node);
	inStack[node] = 1;
	for (int child : adj[node])
		if (!dfs_num[child]) {
			tarjan(child);
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (inStack[child])
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
	if (dfs_low[node] == dfs_num[node]) {
		scc++;
		int v = -1;
		while (v != node) {
			v = stk.top(); stk.pop();
			inStack[v] = 0;
		}
	}
}


int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		adj = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				char ch; cin >> ch;
				if (ch == 'Y')
					adj[i].push_back(j);
			}
		inStack = vector<bool>(n + 1);
		dfs_low = dfs_num = vector<int>(n + 1);
		scc = timer = 0;
		for (int i = 1; i <= n; i++)
			if (!dfs_num[i])tarjan(i);
		cout << scc << endl;
	}
}
