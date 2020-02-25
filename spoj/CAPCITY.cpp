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

vector<vector<int>> adj, scc;
vector<set<int>> DAG;
vector<int> dfs_num, dfs_low, compID;
vector<bool> inStack;
stack<int> stk;
int timer;
void tarjan(int node) {
	dfs_num[node] = dfs_low[node] = ++timer;
	inStack[node] = 1;
	stk.push(node);
	for (int child : adj[node])
		if (!dfs_num[child]) {
			tarjan(child);
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (inStack[child])
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
	if (dfs_num[node] == dfs_low[node]) {
		scc.push_back(vector<int>());
		int v = -1;
		while (v != node) {
			v = stk.top(); stk.pop();
			scc.back().push_back(v);
			compID[v] = sz(scc) - 1;
			inStack[v] = 0;
		}
	}
}
vector<int> in;
int bfs() {
	queue<int> q;
	for (int i = 0; i < sz(DAG); i++)
		if (!in[i])q.push(i);
	int cur;
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int child : DAG[cur]) {
			in[child]--;
			if (!in[child])q.push(child);
		}
	}
	return cur;
}
int main() {
	run();
	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	dfs_num = dfs_low = compID = vector<int>(n + 1);
	inStack = vector<bool>(n + 1);
	while (m--) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		if (!dfs_num[i])tarjan(i);
	DAG = vector<set<int>>(scc.size());
	in = vector<int>(scc.size());
	for (int i = 1; i <= n; i++)
		for (int j : adj[i])
			if (compID[i] != compID[j]
				&& DAG[compID[i]].find(compID[j]) == DAG[compID[i]].end()) {
				DAG[compID[i]].insert(compID[j]);
				in[compID[j]]++;
			}
	int ans = bfs();
	cout << sz(scc[ans]) << endl;
	sort(all(scc[ans]));
	for (int it : scc[ans])
		cout << it << ' ';
}
