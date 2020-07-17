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
vector<vector<char>> v;
vector<vector<bool>> vis;
bool valid(int i, int j) {
	return 0 <= i && i < sz(v) && 0 <= j && j < sz(v[0]) && !vis[i][j] && v[i][j] != '#';
}
int dfs(int i, int j) {
	bool b = 0;
	vis[i][j] = 1;
	for (int k = 0; k < 8; k += 2) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y))
			b |= (v[x][y] == 'T');
	}
	if (b)return 0;
	int cnt = 0;
	for (int k = 0; k < 8; k += 2) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y)) {
			cnt += (v[x][y] == 'G') + dfs(x, y);
		}
	}
	return cnt;
}
int main() {
	run();
	int n, m;
	while (cin >> m >> n) {
		v = vector<vector<char>>(n, vector<char>(m));
		vis = vector<vector<bool>>(n, vector<bool>(m));
		pair<int, int> p;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				if (v[i][j] == 'P')
					p = { i,j };
			}
		cout << dfs(p.first, p.second) << endl;
	}
}