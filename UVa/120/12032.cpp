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
int n;
vector<ll> v;
bool ok(ll k) {
	for (int i = 1; i <= n; i++) {
		if (v[i - 1] + k == v[i])k--;
		else if (v[i - 1] + k < v[i]) return 0;
	}
	return 1;
}
int main() {
	Fast;
	file();
	int t; cin >> t;
	int I = t;
	while (t--) {
		cout << "Case " << I - t << ": ";
		cin >> n;
		v.clear(); v.resize(n + 2);
		for (int i = 1; i <= n; i++)cin >> v[i];
		ll st = 0, ed = 1e10, mid, k = INT_MAX;
		while (st <= ed) {
			mid = (ed + st) >> 1;
			if (ok(mid)) ed = mid - 1, k = mid;
			else st = mid + 1;
		}
		cout << k << endl;
	}
}
