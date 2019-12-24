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
int dr[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[] { 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif
}

int main() {
	run();
	int n, m;
	while (cin >> n >> m) {
		vector<int> v(n + 9);
		map<int, vector<int>> mp;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 1; i <= n; i++) {
			if (mp[v[i]].empty())
				mp[v[i]].push_back(0);
			mp[v[i]].push_back(i);
		}
		while (m--) {
			int k, x;
			cin >> k >> x;
			if (mp[x].empty() || sz(mp[x]) <= k)
				cout << 0 << endl;
			else
				cout << mp[x][k] << endl;
		}

	}
}
