#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
#define oo ll(2e10)
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);//freopen("output.out", "w", stdout);
#endif
}
int n;
vector<pair<ll, ll>> v;
map<pair<int, ll>, ll> mp;
ll mnCost(int ind, ll vol) {
	if (ind >= n) {
		if (vol > 0)return oo;
		return 0;
	}
	if (mp.find({ ind,vol }) != mp.end())
		return mp[{ind, vol}];
	ll mn = mnCost(ind + 1, vol);
	mn = min(mn, v[ind].second +
		mnCost(ind + 1, vol - v[ind].first));
	return mp[{ind, vol}] = mn;
}

int main() {
	run();
	cin >> n;
	v.clear(); mp.clear();
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case " << I << ": ";
		int v, x; cin >> v >> x;
		v = (v + x - 1) / x;
		ll mn = mnCost(0, v);
		if (mn == oo)cout << "IMPOSSIBLE" << endl;
		else cout << mn << endl;
	}
}
