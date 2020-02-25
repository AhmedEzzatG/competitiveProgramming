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
const int N = 185;
int ans[N][N], n, m;
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}
void bfs(queue<pair<int, int>>& q) {
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k += 2) {
			int x = i + dr[k], y = j + dc[k];
			if (valid(x, y) && ans[x][y] > ans[i][j] + 1) {
				ans[x][y] = ans[i][j] + 1;
				q.push({ x,y });
			}
		}
	}
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(ans, oo);
		cin >> n >> m;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char ch; cin >> ch;
				if (ch == '1') {
					ans[i][j] = 0;
					q.push({ i,j });
				}
			}
		bfs(q);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[i][j] << ' ';
			cout << endl;
		}
	}
}
