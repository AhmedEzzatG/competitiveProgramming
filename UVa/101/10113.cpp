#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

using pll = pair<ll,ll>;
pll NLL = pll(-1, -1);
pll v[61][61];
pll merge(pll a, pll b) {
	if (a == NLL || b == NLL)
		return NLL;
	ll x = a.first * b.first, y = a.second * b.second;
	ll g = __gcd(x, y);
	x /= g;
	y /= g;
	return {x,y};
}
int main() {
	run();
	memset(v, -1, sizeof v);
	for (int i = 0; i < 60; i++)
		v[i][i] = { 1, 1 };
	char ch;
	int cnt = 0;
	map<string, int> mp;
	while (cin >> ch, ch != '.') {
		int a, b;
		string x, y;
		if (ch == '!') {
			cin >> a >> x >> ch >> b >> y;
			int g = __gcd(a, b);
			a /= g;
			b /= g;
			if (mp.find(x) == mp.end())
				mp[x] = cnt++;
			if (mp.find(y) == mp.end())
				mp[y] = cnt++;
			int idx = mp[x], idx2 = mp[y];
			v[idx][idx2] = { a, b };
			v[idx2][idx] = { b, a };
			for (int k = 0; k < cnt; k++)
				for (int i = 0; i < cnt; i++)
					for (int j = 0; j < cnt; j++)
						if (v[i][j] == NLL)
							v[i][j] = merge(v[i][k], v[k][j]);
		} else {
			cin >> x >> ch >> y;
			if (mp.find(x) == mp.end())
				mp[x] = cnt++;
			if (mp.find(y) == mp.end())
				mp[y] = cnt++;
			int idx = mp[x], idx2 = mp[y];
			if (v[idx][idx2].first == -1)
				cout << '?';
			else
				cout << v[idx][idx2].first;
			cout << ' ' << x << " = ";
			if (v[idx][idx2].second == -1)
				cout << '?';
			else
				cout << v[idx][idx2].second;
			cout << ' ' << y << endl;
		}
	}
}
