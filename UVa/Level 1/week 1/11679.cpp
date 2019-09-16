#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(), s.rend()
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
int main() {
	Fast;
	file();
	int n, b;
	while (cin >> b >> n) {
		if (!n && !b) return 0;
		vector<int> money(b);
		for (int i = 0; i < b; i++)
			cin >> money[i];
		for (int i = 0; i < n; i++) {
			int d, c, v;
			cin >> d >> c >> v;
			money[d - 1] -= v;
			money[c - 1] += v;
		}
		bool s = 1;
		for (int i = 0; s && i < b; i++)
			if (money[i] < 0)s = 0;
		cout << (s ? 'S' : 'N') << endl;
	}
}
