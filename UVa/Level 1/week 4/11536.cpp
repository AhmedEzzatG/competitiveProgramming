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
int main() {
	Fast;
	file();
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case " << I << ": ";
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> v(n);
		int i = 0;
		while (i < 3)v[i] = i + 1, i++;
		while (i < n) {
			for (int j = i - 3; j < i; j++)
				v[i] += v[j];
			v[i] %= m;
			v[i++]++;
		}
		int l = 0, r = 0, mn = INT_MAX;
		map<int, int> mp;
		while (l < n) {
			while (r < n) {
				if (sz(mp) == k) break;
				if (v[r] <= k) mp[v[r]]++;
				r++;
			}
			if (sz(mp) < k) break;
			mn = min(mn, r - l);
			if (v[l] <= k) {
				mp[v[l]]--;
				if (mp[v[l]] == 0)mp.erase(v[l]);
			}
			l++;
		}
		if (mn == INT_MAX)
			cout << "sequence nai";
		else cout << mn;
		cout << endl;
	}
}
