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
#define ft first
#define sd second
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}
vector<pair<ll, ll>> v;
int lower(int s, int e, ll x) {
	int st = s, ind = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid].first <= x)
			ind = mid, s = mid + 1;
		else e = mid - 1;
	}
	if (ind != -1) {
		e = ind; ll mx = 0;
		while (st <= e) {
			if (v[e].second > mx)
				mx = v[e].second, ind = e;
			e--;
		}
	}
	return ind;
}

int main() {

	Fast;
	file();
	ll l, n;
	while (cin >> l >> n, (l || n)) {
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		for (int i = 0; i < n; i++) {
			pair<ll, ll> p;
			p.first = max(v[i].first - v[i].second, 0ll);
			p.second = min(v[i].first + v[i].second, l);
			v[i] = p;
		}
		sort(all(v));
		int i = lower(0, n - 1, 0), cnt = 0;
		if (i == -1) cout << -1 << endl;
		else {
			cnt++;
			while (i < n) {
				if (v[i].second == l) { break; }
				i = lower(i + 1, n - 1, v[i].second);
				if (i == -1) { cnt = -1; break; }
				cnt++;
			}
			cout << (cnt == -1 ? -1 : n - cnt) << endl;
		}
	}
}
