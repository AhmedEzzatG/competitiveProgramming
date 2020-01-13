#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}


vector<vector<int>> adj;
vector<int> col, rt, cur;
void solve(int idx) {
	if (idx == sz(adj)) {
		if (sz(cur) > sz(rt)) rt = cur;
		return;
	}
	bool valid = true;
	for (int ch : adj[idx]) if (col[ch] == 1) {
		valid = false;
		break;
	}
	if (valid) {
		col[idx] = 1;
		cur.push_back(idx);
		solve(idx + 1);
		col[idx] = 0;
		cur.pop_back();
	}
	solve(idx + 1);
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		adj = vector<vector<int>>(n + 1);
		col = vector<int>(n + 1);
		rt.clear();
		while (m--) {
			int u, v; cin >> u >> v;
			adj[max(u, v)].push_back(min(u, v));
		}
		solve(1);
		cout << rt.size() << endl;
		for (int i = 0; i < sz(rt); i++)
			cout << rt[i] << " \n"[i + 1 == sz(rt)];
	}
}
