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
#define RT(s,v) return cout<<s,v
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	int t; cin >> t;
	for (int I = 1; I <= t;I++) {
		cout << "Case " << I << ": ";
		int n; cin >> n;
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '.')cnt++, i += 2;
		}
		cout << cnt << endl;
	}
}
