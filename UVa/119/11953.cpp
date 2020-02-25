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
int n;
char arr[110][110];
bool vis[110][110];
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n &&
		!vis[i][j] && (arr[i][j] == '@' || arr[i][j] == 'x');
}
void dfs(int i,int j) {
	vis[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y))
			dfs(x, y);
	}
}

int connectedComp() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || arr[i][j] != 'x')
				continue;
			dfs(i, j); cnt++;
		}
	}
	return cnt;
}

int main() {
	run();
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		int cnt = connectedComp();
		cout << "Case " << I << ": " << cnt << endl;
		clr(vis, 0);
	}
}
