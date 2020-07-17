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
const int N = 1002;
vector<int> fac[N];
void primeFactors() {
	for (int i = 2; i < N; i += 2)
		fac[i].push_back(2);
	for (int i = 3; i < N; i += 2) {
		if (fac[i].empty()) for (int j = i; j < N; j += i)
			fac[j].push_back(i);
	}
}

void Min(int& a, int b) { a = min(a, b); }
int main() {
	run();
	primeFactors();
	vector<vector<int>> dp(101, vector<int>(1001, oo));
	for (int s = 1; s <= 100; s++) {
		dp[s][s] = 0;
		for (int t = s; t < 1000; t++) {
			if (dp[s][t] == oo)continue;
			for (auto a : fac[t]) {
				if (a == t)continue;
				if (t + a > 1000)break;
				Min(dp[s][t + a], 1 + dp[s][t]);
			}
		}
	}
	int I = 1, s, t;
	while (cin >> s >> t, s || t) {
		cout << "Case " << I++ << ": ";	
		cout << (dp[s][t] == oo ? -1 : dp[s][t]) << endl;
	}
}