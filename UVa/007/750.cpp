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
vector<vector<int>> ans;
unordered_map<int, bool> row, dig1, dig2;
void queen(vector<int>& v, int col = 1) {
	if (col > 8) return ans.push_back(v);
	if (v[col])queen(v, col + 1);
	else for (int i = 1; i <= 8; i++) {
		if (!row[i] && !dig1[col + i] && !dig2[col - i]) {
			v[col] = i;
			row[i] = dig1[col + i] = dig2[col - i] = 1;
			queen(v, col + 1);
			row[i] = dig1[col + i] = dig2[col - i] = v[col] = 0;
		}
	}
}

int main() {
	run();
	int t; cin >> t;
	bool b = 0;
	while (t--) {
		if (b)cout << endl;
		b = 1;
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		ans.clear();
		row.clear(); dig1.clear(); dig2.clear();
		vector<int> v(9);
		int x, y; cin >> y >> x;
		v[x] = y;
		row[y] = dig1[x + y] = dig2[x - y] = 1;
		queen(v);
		for (int i = 0; i < sz(ans); i++) {
			if (i < 9)cout << ' ';
			cout << i + 1;
			for (int j = 0; j < 5; j++)
				cout << ' ';
			for (int j = 1; j <= 8; j++)
				cout << ' ' << ans[i][j];
			cout << endl;
		}
	}
}
