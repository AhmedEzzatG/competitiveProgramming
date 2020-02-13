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
ll power(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll r = power(x, y >> 1);
	return r * r * power(x, y & 1);
}
int main() {
	Fast;
	file();
	ll n;
	while (cin >> n, n > 0) {
		cout << n << " coconuts, ";
		ll p = -1, x;
		for (x = 2; floor(x * log(x)) <= log(n); x++) {
			ll nn = n, I = x;
			bool b = 1;
			while (I--) {
				if (nn% x == 1) {
					nn /= x;
					nn *= (x - 1);
				}
				else { b = 0; break; }
			}
			if (b&& nn% x == 0) p = x;
		}
		if (p > 0)
			cout << p << " people and 1 monkey" << endl;
		else cout << "no solution" << endl;
	}
}
