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
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);freopen("output.out", "w", stdout);
#endif
}
int n, m;
vector<vector<bool>> v;
map<pair<int, int>, int> mp;
bool valid(int i, int j) { return  i <= n && j <= m; }
int cntPath(int i, int j) {
	if (i == n && j == m)return 1;
	if (!valid(i, j) || v[i][j])return 0;
	if (mp.find({ i,j }) != mp.end())return mp[{i, j}];
	int cnt = cntPath(i + 1, j) + cntPath(i, j + 1);
	mp[{i, j}] = cnt;
	return cnt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		v.clear(); mp.clear();
		v.resize(n + 2, vector<bool>(m + 2));
		cin.ignore();
		for (int i = 1; i <= n; i++) {
			int x = 0, y = 0;
			bool b = true;
			string s; getline(cin, s);
			for (char ch : s) {
				if (b) {
					if (ch == ' ' || ch == endl)
						b = false;
					else x = x * 10 + ch - '0';
				}
				else {
					if (ch == ' ' || ch == endl) {
						v[x][y] = true;
						y = 0;
					}
					else y = y * 10 + ch - '0';
				}
			}
			v[x][y] = true;
		}
		cout << cntPath(1, 1) << endl;
		if (t > 0)cout << endl;
	}
}
