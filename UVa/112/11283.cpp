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
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
char grid[4][4];
bool vis[4][4];
map<int, int> point{ {3,1},{4,1},{5,2},{6,3},{7,5},{8,11} };
string s;
bool valid(int idx, int i, int j) {
	return 0 <= i && i < 4 && 0 <= j && j < 4 && !vis[i][j] && grid[i][j] == s[idx];
}

bool dfs(int idx, int i, int j) {
	if (idx == sz(s) - 1)return 1;
	vis[i][j] = 1; bool b = 0;
	for (int k = 0; k < 8; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (!valid(idx + 1, x, y))continue;
		if (dfs(idx + 1, x, y)) { b = 1; break; }
	}
	vis[i][j] = 0;
	return b;
}
bool find() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (valid(0, i, j) && dfs(0, i, j))return 1;
	return 0;
}
int main() {
	run();
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> grid[i][j];
		int m; cin >> m;
		int ans = 0;
		set<string> st;
		while (m--) {
			cin >> s;
			if (find()) st.insert(s);
		}
		for (auto s : st)
			if (sz(s) >= 8)ans += 11;
			else ans += point[sz(s)];
		cout << "Score for Boggle game #" << I << ": " << ans << endl;
	}
}