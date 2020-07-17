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
	freopen("output.out", "w", stdout);
#else
#endif
}

int mem[1009][1009];
int solve(int cur, int rem) {
	if (rem == 0)return 0;
	if (rem < 0 || cur > rem)return -oo;
	int& rt = mem[cur][rem];
	if (~rt)return rt;
	rt = solve(cur + 1, rem);
	rt = max(rt, 1 + solve(cur + 1, rem - cur));
	return rt;
}

void build(int cur, int rem) {
	if (rem == 0 || rem < 0 || cur > rem)return;
	if (solve(cur,rem) == solve(cur + 1, rem))
		build(cur + 1, rem);
	else {
		cout << cur << " \n"[rem - cur == 0];
		build(cur + 1, rem - cur);
	}
}
int main() {
	run();
	clr(mem, -1);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		build(2, n);
		if (t)cout << endl;
	}
}