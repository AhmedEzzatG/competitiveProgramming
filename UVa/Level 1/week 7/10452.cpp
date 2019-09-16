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
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}
int n, m;
const int MX = 10;
unordered_map<char, bool> mp;
vector<string> X = { "","forth","right","left" };
char arr[MX][MX];
bool vis[MX][MX];
bool valid(int i, int j) {
	return 0 < i&& i <= n && 0 < j && j <= m && !vis[i][j]
		&& mp[arr[i][j]];
}

vector<vector<int>> ans;
void dfs(int i, int j,vector<int> v) {
	if (arr[i][j] == '#') {
		ans.push_back(v);
		return;
	}
	vis[i][j] = true;
	for (int k = 1; k < 4; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y)) {
			v.push_back(k);
			dfs(x, y, v);
			v.pop_back();
		}
	}
}

int main() {
	run();
	for (auto ch : "#IEHOVA")
		mp[ch] = true;
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		pair<int, int> st;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					st.first = i, st.second = j;
			}
		int cnt = 0;
		dfs(st.first, st.second, {});
		sort(all(ans));
		cout << X[ans[0][0]];
		for (int i = 1; i < sz(ans[0]); i++)
			cout << ' ' << X[ans[0][i]];
		cout << endl;
		clr(vis, 0);
		ans.clear();
	}
}
