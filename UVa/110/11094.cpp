#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v) return cout<<v,0
#define watch(x) cout << (#x) << " = " << x << endl
#define oo INT_MIN
int dr[] { -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[] { 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}

int n, m;
char ch;
vector<vector<char>> v;
vector<vector<bool>> vis;
int fixMod(int a, int b) {
	return (a % b + b) % b;
}
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && !vis[i][j] && v[i][j] == ch;
}

int dfs(int i, int j) {
	if (vis[i][j])
		return 0;
	vis[i][j] = true;
	int cnt = 1;
	for (int k = 0; k < 4; k++) {
		int x = i + dr[k], y = fixMod(j + dc[k], m);
		if (valid(x, y))
			cnt += dfs(x, y);
	}
	return cnt;
}

int solve() {
	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (valid(i, j))
				mx = max(mx, dfs(i, j));
	return mx;
}

int main() {
	run();
	while (cin >> n >> m) {
		v.clear();
		vis.clear();
		v.resize(n, vector<char>(m));
		vis.resize(n, vector<bool>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		int x, y;
		cin >> x >> y;
		ch = v[x][y];
		dfs(x,y);
		cout << solve() << endl;
	}
}
