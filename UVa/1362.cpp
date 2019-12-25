#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
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
string s;
const int mod = 1e9;
void add(int& a, int b) {
	if ((a += b) >= mod)a -= mod;
}

int multiply(int a, int b) {
	return (1ll * a * b) % mod;
}

int mem[309][309];
int solve(int l, int r) {
	int& rt = mem[l][r];
	if (~rt)return rt;
	if (l == r)return rt = 1;
	if (s[l] != s[r])return rt = 0;
	rt = 0;
	for (int k = l + 2; k <= r; k++)
		if (s[l] == s[k])
			add(rt, multiply(solve(l + 1, k - 1), solve(k, r)));
	return rt;
}

int main() {
	run();
	while (cin >> s) {
		clr(mem, -1);
		cout << solve(0, sz(s)-1) << endl;
	}
}
