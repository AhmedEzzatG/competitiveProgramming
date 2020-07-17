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
	freopen("output.out", "w", stdout);
#else
#endif
}
const int N = 1009;
bool grid[N][N];
int dep[N][N], n, m;
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && !grid[i][j];
}
int bfs(pair<int, int> st, pair<int, int> ed) {
	clr(dep, oo);
	queue<pair<int, int>> q;
	q.push(st); dep[st.first][st.second] = 0;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second; q.pop();
		for (int k = 0; k < 8; k += 2) {
			int x = i + dr[k], y = j + dc[k];
			if (valid(x, y) && dep[x][y] > dep[i][j] + 1) {
				dep[x][y] = dep[i][j] + 1;
				q.push({ x,y });
			}
		}
	}
	return dep[ed.first][ed.second];
}
int main() {
	run();
	while (cin >> n >> m, n || m) {
		clr(grid, 0);
		int x;
		cin >> x;
		cin.ignore();
		while (x--) {
			int r; cin >> r;
			int c, cnt; cin >> cnt;
			while (cnt--) {
				cin >> c;
				grid[r][c] = 1;
			}
		}
		pair<int, int>st, ed;
		cin >> st.first >> st.second >> ed.first >> ed.second;
		cout << bfs(st, ed) << endl;
	}
}