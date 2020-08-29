#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

const int N = (1 << 12);
int dp[N];
int solve(int mask) {
	int &rt = dp[mask];
	if (~rt)
		return rt;
	rt = __builtin_popcount(mask);
	for (int j = 0; j < 10; j++) {
		int AND = ((mask >> j) & 7);
		if (AND == 3 || AND == 6)
			rt = min(rt, solve(mask ^ (7 << j)));
	}
	return rt;
}
int main() {
	run();
	int T;
	cin >> T;
	memset(dp, -1, sizeof dp);
	while (T--) {
		string s;
		cin >> s;
		int mask = 0;
		for (int i = 0; i < sz(s); i++)
			if (s[i] == 'o')
				mask |= (1 << i);
		cout << solve(mask) << endl;
	}
}