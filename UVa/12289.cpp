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
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	int n; cin >> n;
	string a[]{ "one","two" };
	while (n--) {
		string s; cin >> s;
		if (sz(s) == 5)cout << 3 << endl;
		else {
			int cnt[2] = { 0,0 };
			for (int I = 0; I < 2; I++)
				for (int i = 0; i < sz(s); i++)
					cnt[I] += (s[i] == a[I][i]);
			if (cnt[0] > cnt[1])cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
}
