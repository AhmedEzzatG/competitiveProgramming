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
int flipBit(int num, int ind) { return (num ^ (1 << ind)); }
int main() {
	Fast;
	file();
	int n;
	while (cin >> n) {
		vector<int> v(1 << n);
		vector<int> corner(1 << n);
		for (int i = 0; i < (1 << n); i++)
			cin >> v[i];
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				corner[i] += v[flipBit(i, j)];
		int mx = 0;
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				mx = max(mx, corner[i] + corner[flipBit(i, j)]);
		cout << mx << endl;
	}
}
