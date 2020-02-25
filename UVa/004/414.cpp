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
#define allr(s) s.rbegin(), s.rend()
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	int n;
	while (cin >> n) {
		if (n == 0) return 0;
		cin.ignore();
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			string s; getline(cin, s);
			for (char ch : s)
				if (ch == 'X') v[i]++;
		}
		sort(allr(v));
		int mx = 0;
		for (int i = 1; i < n; i++)
			mx += (v[0] - v[i]);
		cout << mx << endl;
	}
}
