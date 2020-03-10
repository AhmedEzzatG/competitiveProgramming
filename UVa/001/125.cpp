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

vector<vector<ll>> v;
vector<bool> vis, inStack;
bool dfs(int node, int dest) {
	if (vis[node])
		return (inStack[node] && v[node][dest]);
	vis[node] = inStack[node] = 1;
	bool cycle = false;
	for (int i = 0; i < sz(v); i++)
		if (v[node][i] && dfs(i, dest)) {
			cycle = true;
			break;
		}
	inStack[node] = 0;
	return cycle;
}

int main() {
	run();
	int n;
	int I = 0;
	while (cin >> n) {
		cout << "matrix for city " << I++ << endl;
		vector<pair<int, int>> edgeList(n);
		int mx = 0;
		for (auto &it : edgeList) {
			cin >> it.first >> it.second;
			mx = max( { mx, it.first, it.second });
		}
		n = mx + 1;
		vector<vector<ll>> adj(n, vector<ll>(n));
		for (auto &it : edgeList)
			adj[it.first][it.second] = 1;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					adj[i][j] += adj[i][k] * adj[k][j];
		v = adj;
		for (int i = 0; i < sz(adj); i++) {
			for (int j = 0; j < sz(adj); j++) {
				inStack = vis = vector<bool>(adj.size());
				if (dfs(i, j))
					adj[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cout << adj[i][j] << " \n"[j + 1 == n];
	}
}
