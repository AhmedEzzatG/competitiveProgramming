#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
vector<vector<pair<int, int>>> v;

ll solve(int q) {
	ll cost = 0;
	for (auto it : v) {
		int mn = oo;
		for (auto it2 : it)if (it2.second >= q)
			mn = min(mn, it2.first);
		cost += mn;
	}
	return cost;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, b;
		cin >> n >> b;
		map <string, vector<pair<int, int>>> mp;
		for (int i = 0; i < n; i++) {
			string type, name;
			int price, quality;
			cin >> type >> name >> price >> quality;
			mp[type].push_back({ price,quality });
		}
		v.clear();
		for (auto it : mp)v.push_back(it.second);
		mp.clear();
		int st = 0, ed = 2e9, md, ans = 0;
		while (st <= ed) {
			md = st + ed >> 1;
			if (solve(md) <= b)
				st = md + 1, ans = md;
			else ed = md - 1;
		}
		cout << ans << endl;
	}
}
