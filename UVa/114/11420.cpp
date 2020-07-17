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
	//freopen("input.out", "w", stdout);
#else
#endif
}

ll mem[70][70][2];
ll solve(int n, int s, bool op) {
	if (s < 0)return 0;
	if (!n)return s == 0;
	ll& rt = mem[n][s][op];
	if (~rt)return rt;
	rt = 0;
	rt += solve(n - 1, s, true);
	rt += solve(n - 1, s - !op, false);
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	int n, s;
	while (cin >> n >> s, n >= 0 && s >= 0) {
		cout << solve(n, s, false) << endl;
	}
}