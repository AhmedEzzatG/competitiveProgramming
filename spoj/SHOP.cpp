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

vector<vector<char>> s;
int n, m;
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != 'X';
}
int solve() {
	priority_queue<vector<int>> q;
	auto dis = vector<vector<int>>(n, vector<int>(m, oo));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'S') {
				dis[i][j] = 0;
				q.push( { 0, i, j });
			}
	while (sz(q)) {
		int cost = -q.top()[0], i = q.top()[1], j = q.top()[2];
		q.pop();
		if (dis[i][j] < cost)
			continue;
		if (s[i][j] == 'D')
			return cost;
		for (int k = 0; k < 8; k += 2) {
			int x = i + dr[k], y = j + dc[k];
			if (valid(x, y)) {
				cost = (s[x][y] == 'D' ? 0 : s[x][y] - '0');
				if (dis[i][j] + cost < dis[x][y]) {
					dis[x][y] = dis[i][j] + cost;
					q.push( { -dis[x][y], x, y });
				}
			}
		}
	}
	return 0;
}
int main() {
	run();
	while (cin >> m >> n, n && m) {
		s = create<char>(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> s[i][j];
		cout << solve() << endl;
	}
}
