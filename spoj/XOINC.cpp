#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
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
const int N = 2009;
int mem[N][N][2], sum[N], n;

int solve(int idx, int cnt, bool b) {
	if (idx == n + 1)return 0;
	cnt = min(cnt, n - idx + 1);
	if (cnt == 0)return (b ? -oo : oo);
	int& rt = mem[idx][cnt][b];
	if (~rt)return rt;
	rt  = solve(idx, cnt - 1, b);
	int take = solve(idx + cnt, cnt * 2, !b);
	if (b) rt = max(rt, sum[idx + cnt - 1] - sum[idx - 1] + take);
	else rt = min(rt, take);
	return rt;
}

int main() {
	run();
	memset(mem, -1, sizeof(mem));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	cout << solve(1, 2, 1);
}
