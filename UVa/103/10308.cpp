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
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
const int N = 10009;
vector<vector<pair<int, int>>> adj;
pair<int, int> p;
void dfs(int node, int par, int dep) {
	p = max(p, { dep, node });
	for (auto ch : adj[node])
		if (ch.first != par)
			dfs(ch.first, node, dep + ch.second);
}
bool input() {
	adj.clear();
	string line;
	int u, v, w;
	bool b = false;
	while (getline(cin, line)) {
		if (line.empty())
			break;
		b = true;
		stringstream ss(line);
		ss >> u >> v >> w;
		adj.resize(max( { sz(adj), u + 1, v + 1 }));
		adj[u].push_back( { v, w });
		adj[v].push_back( { u, w });
	}
	return b;
}
int main() {
	run();
	while (input()) {
		p = { 0, 1 };
		dfs(1, -1, 0);
		pair<int, int> tmp = p;
		p = { 0, 1 };
		dfs(tmp.second, -1, 0);
		cout << p.first << endl;
	}
}