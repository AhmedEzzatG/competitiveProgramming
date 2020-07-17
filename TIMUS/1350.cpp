#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
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

int main() {
	run();
	int n; cin >> n;
	set<string> st;
	while (n--) {
		string s; cin >> s; st.insert(s);
	}
	cin >> n;
	vector<vector<string>> v(n + 1);
	for (int i = 0; i <= n; i++) {
		int m; cin >> m;
		while (m--) {
			string s; cin >> s;
			v[i].push_back(s);
		}
	}
	int m; cin >> m;
	for (auto it : v[0])st.erase(it);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (auto it : v[i]) {
			if (st.find(it) != st.end())cnt++;
		}
		if (!cnt)cout << "YES\n";
		else if (sz(st) - cnt >= m)cout << "MAYBE\n";
		else cout << "NO\n";
	}
}