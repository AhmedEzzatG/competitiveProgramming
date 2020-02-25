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
#define RT(s,v) return cout<<s,v;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
vector<int> v;
int lower(int s, int e, int x) {
	if (s > e) return -1;
	if (s == e) {
		if (v[s] < x) return s;
		return -1;
	}
	int m = s + (e - s + 1) / 2;
	if (v[m] < x) return lower(m, e, x);
	return lower(s, --m, x);
}
int upper(int s, int e, int x) {
	if (s > e) return -1;
	if (s == e) {
		if (v[s] > x) return s;
		return -1;
	}
	int m = (s + e) / 2;
	if (v[m] <= x) return upper(++m, e, x);
	return upper(s, m, x);
}
int main() {
	Fast;
	file();
	int n, q;
	cin >> n;
	v.resize(n);
	while (n--)cin >> v[n];
	sort(all(v));
	cin >> q;
	while (q--) {
		int x,ind; cin >> x;
		ind = lower(0, sz(v) - 1, x);
		if (ind == -1)cout << "X" << ' ';
		else cout << v[ind] << ' ';
		ind = upper(0, sz(v) - 1, x);
		if (ind == -1)cout << "X" << endl;
		else cout << v[ind] << endl;
	}
}
