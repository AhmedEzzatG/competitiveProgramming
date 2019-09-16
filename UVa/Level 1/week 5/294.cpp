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
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x) << " = " << x << endl
#define numOfDigit(x) 1+(int)log10(x)
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
int divisors(int n) {
	int i, cnt = 0;
	for (i = 1; i * i < n; i++)
		if (!(n% i)) cnt += 2;
	if (i* i == n) cnt++;
	return cnt;
}
int main() {
	file();
	int t;
	while (cin >> t) {
		while (t--) {
			int l, u, x, mx = 0;
			cin >> l >> u;
			for (int i = l; i <= u; i++) {
				int cnt = divisors(i);
				if (cnt > mx) mx = cnt, x = i;
			}
			printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, x, mx);
		}
	}
}
