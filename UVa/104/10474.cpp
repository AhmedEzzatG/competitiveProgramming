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
int binarySearch(int s, int e, int x) {
	if (s > e) return -1;
	if (s == e) {
		if (v[s] == x) return s;
		return -1;
	}
	int m = (s + e) / 2;
	if (v[m] < x) return binarySearch(++m, e, x);
	if (v[m] > x) return binarySearch(s, --m, x);
	if(v[m] == x) return binarySearch(s, m, x);
}
int main() {
	Fast;
	file();
	int n, q;
	int I = 0;
	while (cin >> n >> q, n || q) {
		v.clear();
		cout << "CASE# " << ++I << ":" << endl;
		while (n--) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(all(v));
		while (q--) {
			int x; cin >> x;
			int ind = binarySearch(0, sz(v) - 1, x);
			cout << x << ' ';
			if (ind == -1) cout << "not found" << endl;
			else cout << "found at " << ++ind << endl;
		}
	}
}
