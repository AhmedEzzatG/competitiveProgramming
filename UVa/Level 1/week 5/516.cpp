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
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x) << " = " << x << endl
#define numOfDigit(x) (int)(floor(1+log10(x)))
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
ll power(ll x, ll y) {
	if (y == 0)return 1;
	if (y == 1)return x;
	ll r = power(x, y >> 1);
	return r * r * power(x, y & 1);
}
ll num(vector<pair<int, int>> v) {
	ll nm = 1;
	for (auto it : v) {
		nm *= power(it.first, it.second);
	}
	return nm - 1;
}
map<ll, int> primeFactor(ll n) {
	map <ll, int> mp;
	while (n > 0 && !(n & 1))mp[2]++, n >>= 1;
	for (int i = 3; i <= n; i += 2) {
		while (n % i == 0)mp[i]++, n /= i;
	}
	return mp;
}
int main() {
	Fast;
	file();
	string s;
	while (getline(cin, s), s[0] != '0') {
		vector<pair<int, int>> v;
		bool  b = 1;
		int x = 0, y = 0;
		s.push_back(' ');
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == ' ') {
				if (!b) {
					v.push_back({ x,y });
					x = 0, y = 0;
				}
				b ^= 1;
			}
			else if (b) x = x * 10 + (s[i] - '0');
			else y = y * 10 + (s[i] - '0');
		}
		map<ll, int> mp = primeFactor(num(v));
		auto it = mp.rbegin();
		for (; it != mp.rend(); it++) {
			if (it != mp.rbegin())cout << ' ';
			cout << it->first << ' ' << it->second;
		}
		cout << endl;
	}
}
