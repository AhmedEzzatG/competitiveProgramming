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
ll power(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll r = power(x, y >> 1);
	return r * r* power(x, y & 1);
}
ll conToDec(string s,int base) {
	ll x = 0;
	reverse(all(s));
	for (int i = 0; i < sz(s); i++) {
		if (isdigit(s[i]))
			x += (s[i] - '0') * power(base, i);
		else x += (s[i] - 'A' + 10) * power(base, i);
	}
	return x;
}
string conFromDec(ll x, int base) {
	string s;
	if (x == 0) return "0";
	while (x > 0) {
		if (x% base > 9)
			s.push_back(char(x % base + 'A' - 10));
		else s.push_back(char(x % base + '0'));
		x /= base;
	}
	reverse(all(s));
	return s;
}
int main() {
	Fast;
	file();
	string s;
	int x, y;
	while (cin >> s >> x >> y) {
		ll dec = conToDec(s, x);
		string s = conFromDec(dec, y);
		cout << setw(7) << (sz(s) <= 7 ? s : "ERROR") << endl;
	}
}
