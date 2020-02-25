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

int main() {
	Fast;
	file();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		while (n--)cin >> v[n];
		bool b = 0;
		n = sz(v);
		for (int i = 1; i < (1 << n); i++) {
			bitset<30>bit(i);
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (bit[j]) sum += v[j];
				if (sum >= m) break;
			}
			if (sum == m) {
				b = 1; break;
			}
		}
		cout << (b ? "Yes" : "No") << endl;
	}
}
