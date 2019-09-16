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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
int main() {
	Fast;
	file();
	int t; cin >> t;
	while (t--) {
		ll g, l; cin >> g >> l;
		if (l% g)cout << -1 << endl;
		else {
			bool b = 0;
			ll n = l * g;
			pair<ll, ll> p = { -1,-1 };
			for (ll i = g; i >= 1; i--) {
				if (n % i == 0) {
					ll gc = gcd(i, n / i);
					ll lc = i / gc * (n / i);
					if (gc == g && lc == l) {
						p.first = i;
						p.second = n / i;
						break;
					}
				}
			}
			cout << p.first;
			if(p.second != -1)cout << ' ' << p.second << endl;
		}
	}
}
