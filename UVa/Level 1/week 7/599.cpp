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
vector<char> v;
unordered_map<char,vector<char>> adj;
unordered_map<char, bool> vis;

bool dfs(char node) {
	if (vis[node])return false;
	vis[node] = true;
	bool b = false;
	for (auto child : adj[node]) {
		b = true;
		if (!vis[child])
			dfs(child);
	}
	return b;
}

pair<int,int> connectedComp() {
	pair<int, int> cnt = { 0,0 };
	for (auto ch : v) {
		if (vis[ch]) continue;
		bool b = dfs(ch);
		if (b)cnt.first++;
		else cnt.second++;
	}
	return cnt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		string s;
		while (cin >> s) {
			if (s[0] == '*')break;
			char x = s[1], y = s[3];
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		cin >> s;
		for (int i = 0; i < sz(s); i += 2)
			v.push_back(s[i]);
		pair<int, int> ans = connectedComp();
		cout << "There are " << ans.first <<
			" tree(s) and " << ans.second <<
			" acorn(s)." << endl;
		v.clear();
		adj.clear();
		vis.clear();
	}
}
