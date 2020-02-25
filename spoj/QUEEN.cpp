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
	/*ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);*/
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

const int N = 1009;
char grid[N][N];
int vis[N][N], dis[N][N], n, m;

inline bool valid(int i, int j, int d) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] != 'X'
			&& !(vis[i][j] & (1 << d));
}

int bfs(pair<int, int> &s, pair<int, int> &e) {
	queue<pair<int, int>> q;
	q.push(s);
	dis[s.first][s.second] = 0;
	vis[s.first][s.second] = (1 << 8) - 1;
	int i, j, x, y;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		if (q.front() == e)
			return dis[i][j];
		q.pop();
		for (int k = 0; k < 8; k++) {
			x = i + dr[k];
			y = j + dc[k];
			while (valid(x, y, k)) {
				if (!vis[x][y]) {
					q.push( { x, y });
					dis[x][y] = dis[i][j] + 1;
				}
				vis[x][y] |= (1 << k);
				x += dr[k];
				y += dc[k];
			}
		}
	}
	return -1;
}

int main() {
	run();
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		pair<int, int> s, e;
		for (int i = 0; i < n; i++) {
			scanf("%s", grid + i);
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'S')
					s = { i, j };
				else if (grid[i][j] == 'F')
					e = { i, j };
				vis[i][j] = 0;
				dis[i][j] = oo;
			}
		}
		printf("%d\n", bfs(s, e));
	}
}
