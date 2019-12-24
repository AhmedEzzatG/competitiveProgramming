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

int fixMod(int a, int b) {
	return (a < 0 ? ((a % b) + b) % b : a % b);
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		vector<vector<int>> dp(n + 1, vector<int>(k));
		dp[n][0] = 1;
		for (int i = n - 1; i >= 0; i--)
			for (int rem = 0; rem < k; rem++) {
				dp[i][rem] |= dp[i + 1][fixMod(rem + v[i], k)];
				dp[i][rem] |= dp[i + 1][fixMod(rem - v[i], k)];
			}
		if (dp[0][0])cout << "Divisible\n";
		else cout << "Not divisible\n";
	}
}
