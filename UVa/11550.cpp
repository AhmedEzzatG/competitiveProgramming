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
#define oo INT_MAX
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}
int arr[10][50];
bool vis[10][50];
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(vis, 0);
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		bool ok = true;
		for (int j = 0; ok && j < m; j++) {
			int cnt = 0;
			pair<int, int> p = { -1,-1 };
			for (int i = 0; i < n; i++)
				if (arr[i][j]) {
					cnt++;
					if (cnt == 1)p.first = i;
					else if (cnt == 2)p.second = i;
					else { ok = false; break; }
				}
			if (cnt == 2) {
				if (vis[p.first][p.second] || vis[p.second][p.first])
					ok = false;
				else vis[p.first][p.second] = vis[p.second][p.first] = true;
			}
			else ok = false;
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
}
