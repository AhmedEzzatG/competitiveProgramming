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
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);//can be dfs_low[child]
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
	int n, m;
	while (cin >> n >> m, n || m) {
		cin.ignore();
		adj = vector<vector<int>>(n);
		map<string, int> id;
		string s, s2;
		while (n--) {
			getline(cin, s);
			id[s] = n;
		}
		while (m--) {
			getline(cin, s);
			getline(cin, s2);
			adj[id[s]].push_back(id[s2]);
		}
		timer = scc = 0;
		dfs_num = dfs_low = vector<int>(adj.size());
		inStack = vector<bool>(adj.size());
		for (int i = 0; i < adj.size(); i++)
			if (!dfs_num[i]) tarjan(i);
		cout << scc << endl;
	}
}