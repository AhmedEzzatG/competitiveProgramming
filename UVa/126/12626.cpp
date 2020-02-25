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
	while (n--) {
		string s; cin >> s;
		string a = "MARGIT";
		map<char, int> mp;
		for (char ch : a) mp[ch] = 0;
		for (char ch : s) mp[ch]++;
		mp['A'] /= 3, mp['R'] /= 2;
		int mn = INT_MAX;
		for (auto it : mp) {
			if (a.find(it.first) != string::npos)
				mn = min(mn, it.second);
		}
		cout << mn << endl;
	}
}
