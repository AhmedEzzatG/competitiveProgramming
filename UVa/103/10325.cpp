#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
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

ll gcd(ll a, ll b) {
	return(b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int n, m;
vector<int> v;
int solve(int idx = 0, int cnt = 0, ll num = 1) {
	if (num > n)return 0;
	if (idx == m) {
		return n / num * ((cnt & 1) ? -1 : 1);
	}
	return solve(idx + 1, cnt, num) + solve(idx + 1, cnt + 1, lcm(v[idx], num));
}

int main() {
	run();
	while (cin >> n >> m) {
		v = vector<int>(m);
		for (int i = 0; i < m; i++) cin >> v[i];
		cout << solve() << endl;
	}
}