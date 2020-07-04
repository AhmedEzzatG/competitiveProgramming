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

vector<vector<int>> scc;
vector<set<int>> dag, adj;
vector<int> dfs_num, dfs_low, compId;
vector<bool> inStack, vis;
stack<int> stk;
int timer;

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
		scc.push_back(vector<int>());
		int v = -1;
		while (v != node) {
			v = stk.top(); stk.pop();
			inStack[v] = 0;
			scc.back().push_back(v);
			compId[v] = scc.size() - 1;
		}
	}
}

void SCC() {
	timer = 0;
	dfs_num = dfs_low = compId = vector<int>(adj.size());
	inStack = vector<bool>(adj.size());
	scc = vector<vector<int>>();
	for (int i = 1; i < adj.size(); i++)
		if (!dfs_num[i]) tarjan(i);
}

void DAG() {
	dag = vector<set<int>>(scc.size());
	for (int i = 1; i < adj.size(); i++)
		for (int j : adj[i]) if (compId[i] != compId[j])
			dag[compId[i]].insert(compId[j]);
}

void dfs(int node) {
	if (vis[node])return;
	vis[node] = 1;
	for (int child : dag[node])
		dfs(child);
}

int main() {
	run();
	int n;
	while (cin >> n, n) {
		cin.ignore();
		adj = vector<set<int>>(n);
		map<string, int> id;
		vector<string> v;
		while (n--) {
			string s, x, y;
			getline(cin, s);
			stringstream ss;
			ss << s; ss >> x;
			if (id.find(x) == id.end()) {
				id[x] = sz(v);
				v.push_back(x);
			}
			while (ss >> y) {
				if (id.find(y) == id.end()) {
					id[y] = sz(v);
					v.push_back(y);
				}
				adj[id[x]].insert(id[y]);
			}
		}
		SCC(); DAG();
		vis = vector<bool>(scc.size());
		for (int i = 0; i < sz(scc); i++) {
			if (sz(scc[i]) > 1)dfs(i);
		}
		set<string> ans;
		for (int i = 0; i < sz(scc); i++) {
			if (vis[i]) {
				for (int j : scc[i])
					ans.insert(v[j]);
			}
		}
		cout << sz(ans) << endl;
		if (sz(ans)) {
			auto it = ans.begin();
			cout << *it; it++;
			for (; it != ans.end(); it++)
				cout << ' ' << *it;
		}
		cout << endl;
	}
}