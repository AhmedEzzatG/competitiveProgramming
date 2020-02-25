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
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
#define oo INT_MAX
int dr[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	auto it = freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
int n = 9;
char arr[10][10];
bool vis[10][10];
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

int dfs(int i, int j,int adj[2]) {
	vis[i][j] = true;
	int cnt = 1;
	for (int k = 0; k < 4; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y)) {
			if (arr[x][y] == 'O')
				adj[0]++;
			else if (arr[x][y] == 'X')
				adj[1]++;
		}
	}
	for (int k = 0; k < 4; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y) && !vis[x][y] && arr[x][y] == '.')
			cnt += dfs(x, y, adj);
	}
	return cnt;
}

int cnt[2];

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'O')
					cnt[0]++;
				else if (arr[i][j] == 'X') cnt[1]++;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!vis[i][j] && arr[i][j] == '.') {
					int adj[2] = { 0,0 }, c;
					c = dfs(i, j, adj);
					if (adj[0] == 0 || adj[1] == 0) {
						if (adj[0] > adj[1])
							cnt[0] += c;
						else cnt[1] += c;
					}
				}
			}
		cout << "Black " << cnt[1] <<
			" White " << cnt[0] << endl;
		cnt[0] = cnt[1] = 0;
		clr(vis, 0);
	}
}
