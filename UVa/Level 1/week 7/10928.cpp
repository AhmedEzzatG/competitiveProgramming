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
#define oo ll(1e10)
int dr[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);//freopen("output.out", "w", stdout);
#endif
}
vector<vector<int>> adj;
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		adj.clear(); adj.resize(n + 1);
		cin.ignore();
		for (int i = 1; i <= n; i++) {
			string s; getline(cin, s);
			int x = 0;
			for (char ch : s) {
				if (ch == ' ' || ch == '\n') {
					adj[i].push_back(x); x = 0;
				}
				else x = x * 10 + ch - '0';
			}
			if (x) adj[i].push_back(x);
		}
		vector<int> ans;
		int mn = n;
		for (int i = 1; i <= n; i++) {
			if (sz(adj[i]) < mn) {
				ans.clear(); ans.push_back(i);
				mn = sz(adj[i]);
			}
			else if (sz(adj[i]) == mn)
				ans.push_back(i);
		}
		cout << ans[0];
		for (int i = 1; i < sz(ans); i++)
			cout << ' ' << ans[i];
		cout << endl;

	}

}
