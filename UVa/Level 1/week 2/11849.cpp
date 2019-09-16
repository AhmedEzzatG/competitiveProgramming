#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)return 0;
		map<ll, pair<bool,bool>> mp;
		while (n--) {
			int a; cin >> a;
			mp[a].first = 1;
		}
		while (m--) {
			int a; cin >> a;
			mp[a].second = 1;
		}
		int cnt = 0;
		for (auto it : mp)
			if (it.second.first&& it.second.second)
				cnt++;
		cout << cnt << endl;
	}
}
