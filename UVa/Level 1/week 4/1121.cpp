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
int main() {
	Fast;
	file();
	int n, s;
	while (cin >> n >> s) {
		vector<int> v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		int l = 0, r = 0, mn = INT_MAX; ll sum = 0;
		while (l < n) {
			while (r < n) {
				if (sum >= s) break;
				sum += v[r++];
			}
			if (sum < s) break;
			mn = min(mn, r - l);
			sum -= v[l++];
		}
		cout << (mn < INT_MAX ? mn : 0) << endl;
	}
}
