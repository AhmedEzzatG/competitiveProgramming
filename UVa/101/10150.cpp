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
vector<string> v;
map<string, int> mp;
vector<vector<int>> adj;
int def(int i, int j) {
	string x = v[i], y = v[j];
	int c = 0;
	for (int i = 0; i < sz(x); i++)
		if (x[i] != y[i])c++;
	return c;
}
vector<int> bfs(int start, int end) {
	vector<int> dep(sz(adj), oo), par(sz(adj), -1);
	queue<int> q; q.push(start);
	dep[start] = 0;
	int cur;
	bool ok = false;
	while (!ok && !q.empty()) {
		cur = q.front(); q.pop();
		for (int child : adj[cur]) {
			if (dep[child] > dep[cur] + 1) {
				q.push(child);
				dep[child] = dep[cur] + 1;
				par[child] = cur;
			}
			if (child == end) { ok = true; break; }
		}
	}
	vector<int> path;
	while (end != -1) {
		path.push_back(end);
		end = par[end];
	}
	reverse(all(path));
	return path;
}

int main() {
	run();
	string s;
	while (getline(cin,s)) {
		if (s == "")break;
		mp[s] = sz(v);
		v.push_back(s);
	}
	adj = vector<vector<int>>(sz(v));
	for (int i = 0; i < sz(v); i++)
		for (int j = i + 1; j < sz(v); j++)
			if (sz(v[i]) == sz(v[j]) && def(i, j) == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
	string x, y;
	bool b = 0;
	while (cin >> x >> y) {
		if(b)cout << endl;
		int i = mp[x], j = mp[y];
		vector<int> p = bfs(i, j);
		if (!p.empty() && p[0] == i) {
			for (int it : p)
				cout << v[it] << endl;
		}
		else cout << "No solution.\n";
		b = 1;
	}
}