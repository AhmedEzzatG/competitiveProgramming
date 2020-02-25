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
vector<ll> divisors(ll n) {
	vector<ll> v; ll i;
	for (i = 1; i * i < n; i++)
		if (!(n% i)) v.push_back(i), v.push_back(n / i);
	if (i* i == n) v.push_back(i);
	sort(all(v));
	return v;
}
ll gcd(ll a, ll b) { return !b ? abs(a) : gcd(b, a % b); }

ll lcm(ll a, ll b) { return abs(a / gcd(a, b)) * b; }

int main() {
	Fast;
	file();
	ll n;
	while (cin >> n, n) {
		vector<ll> v = divisors(n);
		ll cnt = 0;
		for (int i = 0; i < sz(v); i++) {
			for (int j = i; j < sz(v); j++) {
				if (lcm(v[i], v[j]) == n)
					cnt++;
			}
		}
		cout << n << ' ' << cnt << endl;
	}
}
