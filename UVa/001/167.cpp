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
	freopen("input.in", "r", stdin); freopen("output.out", "w", stdout);
#endif
}
vector<vector<int>> ans;
vector<int> v(9);
unordered_map<int, bool> row, dig1, dig2;
void queen(int col = 1) {
	if (col > 8) return ans.push_back(v);
	if (v[col])queen(col + 1);
	else for (int i = 1; i <= 8; i++) {
		if (!row[i] && !dig1[col + i] && !dig2[col - i]) {
			v[col] = i;
			row[i] = dig1[col + i] = dig2[col - i] = 1;
			queen(col + 1);
			row[i] = dig1[col + i] = dig2[col - i] = v[col] = 0;
		}
	}
}
int arr[9][9];
int main() {
	run();
	queen();
	int t; cin >> t;
	while (t--) {
		v.clear();
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				cin >> arr[i][j];
		for (auto it : ans) {
			ll cnt = 0;
			for (int i = 1; i <= 8; i++)
				cnt += arr[i][it[i]];
			v.push_back(cnt);
		}
		sort(all(v));
		cout << setw(5) << v.back() << endl;
	}
}
