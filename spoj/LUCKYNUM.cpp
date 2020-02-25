#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
int x;
int mem[201][10009];
int solve(int idx, int rem, bool b) {
	if (idx > 0 && rem == 0)return 0;
	if (idx == 200)return oo;
	int& rt = mem[idx][rem];
	if (~rt)return rt;
	rem = (rem * 10) % x;
	int ch1 = 1 + solve(idx + 1, (rem + 6) % x, 1), ch2 = oo;
	if(!b)ch2 = 1 + solve(idx + 1, (rem + 8) % x, 0);
	return rt = min(ch1, ch2);
}
void build(int idx, int rem,bool b) {
	if (idx > 0 && rem == 0)return;
	if (idx == 200)return;
	int rt = solve(idx, rem, b);
	rem = (rem * 10) % x;
	int ch1 = 1 + solve(idx + 1, (rem + 6) % x, 1), ch2 = oo;
	if (!b) ch2 = 1 + solve(idx + 1, (rem + 8) % x, 0);
	if (rt == ch1) {
		cout << 6;
		build(idx + 1, (rem + 6) % x, 1);
	}
	else {
		cout << 8;
		build(idx + 1, (rem + 8) % x, 0);
	}
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		cin >> x;
		clr(mem, -1);
		if (solve(0, 0, 0) <= 200)build(0, 0, 0);
		else cout << -1;
		cout << endl;
	}
}
