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
int n, m;
vector<pair<int,int>> v;
bool vis[20];
bool can(int cnt, int st, int ed) {
	if (cnt == n) return (st == ed);
	bool c = 0;
	for (int i = 0; !c && i < m; i++) {
		if (vis[i]) continue;
		if (v[i].first == st) {
			vis[i] = 1;
			c = can(cnt + 1, v[i].second, ed);
			vis[i] = 0;
		}
		if (!c && v[i].second == st) {
			vis[i] = 1;
			c = can(cnt + 1, v[i].first, ed);
			vis[i] = 0;
		}
	}
	return c;
}

int main() {
	run();
	while (cin >> n, n) {
		cin >> m;
		pair<int, int> st, ed;
		cin >> st.first >> st.second;
		cin >> ed.first >> ed.second;
		v.clear();v.resize(m);
		for (int i = 0; i < m; i++)
			cin >> v[i].first >> v[i].second;
		bool b = can(0, st.second, ed.first);
		if (b)cout << "YES" << endl;
		else cout << "NO" << endl;
		clr(vis, 0);
	}
}
