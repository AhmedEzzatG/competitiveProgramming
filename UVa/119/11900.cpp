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
	int t; cin >> t;
	int I = t;
	while (t--) {
		cout << "Case " << I - t << ": ";
		int n, p, q, sum = 0;
		cin >> n >> p >> q;
		vector<int> v(n);
		int i = 0;
		while(i < n)cin >> v[i++];
		i = 0;
		while (i < n && i < p && sum + v[i] <= q)
			sum += v[i++];
		cout << i << endl;
	}
}
