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
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
ll power(ll x, ll y, ll mod) {
	if (y == 0) return 1;
	if (y == 1) return x % mod;
	ll r = power(x, y >> 1, mod) % mod;
	return (((r * r) % mod) * power(x, y & 1, mod)) % mod;
}
int main() {
	Fast;
	file();
	ll x, y, m;
	while (cin >> x >> y >> m) {
		cout << power(x, y, m) << endl;
	}
}
