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

vector<int> v;
int n, k;
int mem[10001][21][21];
int solve(int i = 0, int shiftL = 0, int shiftR = 0) {
	if (shiftR + shiftL > k)return 21;
	int j = n - i - 1 - shiftL + shiftR;
	if (j <= i)return 0;
	int& rt = mem[i][shiftL][shiftR];
	if (~rt)return rt;
	rt = 21;
	if (v[i] == v[j]) rt = solve(i + 1, shiftL, shiftR);
	rt = min(rt, 1 + solve(i + 1, shiftL, shiftR + 1));
	rt = min(rt, 1 + solve(i, shiftL + 1, shiftR));
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case " << I << ": ";
		clr(mem, -1);
		cin >> n >> k;
		v = vector<int>(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		if (solve() == 0)cout << "Too easy";
		else if (solve() <= k) cout << solve();
		else cout << "Too difficult";
		cout << endl;
	}
}
