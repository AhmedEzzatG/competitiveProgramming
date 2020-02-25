#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);freopen("output.out", "w", stdout);
#endif
}
int n, v[110];
int mp[110][50100];
int mnDefr(int ind = 0, int sm = 0, int sm2 = 0) {
	if (ind >= n)return abs(sm2 - sm);
	if (mp[ind][sm] != -1)return mp[ind][sm];
	if (mp[ind][sm2] != -1)return mp[ind][sm2];
	int mn = mnDefr(ind + 1, sm, sm2 + v[ind]);
	mn = min(mn, mnDefr(ind + 1, sm + v[ind], sm2));
	return mp[ind][sm] = mp[ind][sm2] = mn;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		cin >> n;
		clr(v, 0); clr(mp, -1);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << mnDefr() << endl;
	}
}
