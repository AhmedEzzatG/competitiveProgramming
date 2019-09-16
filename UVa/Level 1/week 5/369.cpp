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
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
vector<int> v(200);
int lastDigit() {
	int l = 200;
	while (v[l] == 0 && l > 0)l--;
	return l;
}
void reset() {
	for (int i = 0; i < 200; i++) {
		if (v[i] > 9) {
			v[i + 1] += v[i] / 10;
			v[i] %= 10;
		}
	}
}
void dev(int i) {
	int l = lastDigit();
	ll x = 0;
	while (l >= 0) {
		while (x < i && l >= 0) {
			x = x * 10 + v[l];
			v[l] = 0; l--;
		}
		l++;
		v[l] = x / i;
		x %= i;
		l--;
		reset();
	}
}
void nCr(int n, int r) {
	v[0] = 1;
	for (int i = n - r + 1; i <= n; i++) {
		int l = lastDigit();
		for (int j = 0; j <= l; j++)
			v[j] *= i;
		reset();
	}
	for (int i = 2; i <= r; i++) {
		reset(); dev(i);
	}
	reset();
}
string value() {
	reset();
	int l = lastDigit();
	string s;
	for (int i = 0; i <= l; i++)
		s.push_back(char('0' + v[i]));
	reverse(all(s));
	return s;
}
int main() {
	Fast;
	file();
	int n, r;
	while (cin >> n >> r, (n || r)) {
		for (int i = 0; i < 200; i++)
			v[i] = 0;
		cout << n << " things taken " << r <<
			" at a time is ";
		nCr(n, r);
		cout << value();
		cout << " exactly." << endl;
	}
}
