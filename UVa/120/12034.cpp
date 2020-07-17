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
const int mod = 10056;
int Pascal[1009][1009];
int nCr(int n, int r) {
	if (r > n || n < 0 || r < 0)return 0;
	if (r == 0 || n == r) return 1;
	int& rt = Pascal[n][r];
	if (~rt)return rt;
	return rt = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
}

int mem[1001];
int solve(int rem) {
	if (rem == 0)return 1;
	int& rt = mem[rem];
	if (~rt)return rt;
	rt = 0;
	for (int i = 1; i <= rem; i++)
		rt = (rt + (nCr(rem, i) * solve(rem - i)) % mod) % mod;
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	clr(Pascal, -1);
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			nCr(i, j);
	for (int i = 1; i <= 1000; i++)
		solve(i);
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case " << I << ": ";
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}