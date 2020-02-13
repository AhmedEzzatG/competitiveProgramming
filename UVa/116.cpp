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

int n, m;
vector<vector<int>> grid;
ll mem[101][101];
ll minCost(int i, int j) {
	if (j == m)
		return 0;
	ll &rt = mem[i][j];
	if (rt < INF)
		return rt;
	for (int d = -1; d <= 1; d++)
		rt = min(rt, minCost((i + d + n) % n, j + 1));
	rt += grid[i][j];
	return rt;
}

void build(int i, int j) {
	if (j == m)
		return;
	ll rt = mem[i][j];
	rt -= grid[i][j];
	int mn = n;
	for (int d = -1; d <= 1; d++)
		if (rt == minCost((i + d + n) % n, j + 1))
			mn = min(mn, (i + d + n) % n);
	cout << i + 1 << " \n"[j + 1 == m];
	build(mn, j + 1);
}

int main() {
	run();
	while (cin >> n >> m) {
		memset(mem, oo, sizeof(mem));
		grid = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];
		ll rt = INF, idx = 0;
		for (int i = 0; i < n; i++) {
			ll ans = minCost(i, 0);
			if (ans < rt) {
				rt = ans;
				idx = i;
			}
		}
		build(idx, 0);
		cout << rt << endl;
	}

}
