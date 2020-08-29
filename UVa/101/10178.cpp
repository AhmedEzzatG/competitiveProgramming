#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
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
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

vector<vector<int>> adj;
vector<bool> vis;
pair<int, int> dfs(int node) {
	if (vis[node])
		return {0,0};
	vis[node] = true;
	int cnt_nodes = 1, cnt_edges = 0;
	for (int ch : adj[node]) {
		pair<int, int> p = dfs(ch);
		cnt_nodes += p.first;
		cnt_edges += 1 + p.second;
	}
	return {cnt_nodes,cnt_edges};
}

int main() {
	run();
	int n, e;
	while (cin >> n >> e) {
		adj = vector<vector<int>>(n);
		map<int, int> mp;
		int cnt = 0;
		while (e--) {
			char ch, ch2;
			cin >> ch >> ch2;
			if (mp.find(ch) == mp.end())
				mp[ch] = cnt++;
			if (mp.find(ch2) == mp.end())
				mp[ch2] = cnt++;
			adj[mp[ch]].push_back(mp[ch2]);
			adj[mp[ch2]].push_back(mp[ch]);
		}
		vis = vector<bool>(n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (!vis[i]) {
				// v-e+f=2 -> f = 2 + e -v
				pair<int, int> p = dfs(i);
				p.second /= 2;
				ans += 1 + p.second - p.first;
			}
		cout << ans + 1 << endl;
	}
}