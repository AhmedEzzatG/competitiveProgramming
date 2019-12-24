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
void pls(string &s,int j,char ch) {
	if (j < 0) {
		string y(sz(s) + 1, 'a');
		for (int i = 0; i <= sz(s); i++)y[i] += i;
		s = y;
	}
	else if (s[j] < ch) {
		s[j]++;
		for (j++; j < sz(s); j++)
			s[j] = s[j - 1] + 1;
	}
	else pls(s, --j, --ch);
}

int main() {
	Fast;
	file();
	string s = "a";
	map<string, int> mp;
	for (int i = 1; i <= 83681; i++) {
		mp[s] = i;
		pls(s, sz(s) - 1, 'z');
	}
	s.clear();
	while (cin >> s) { cout << mp[s] << endl; }
}
