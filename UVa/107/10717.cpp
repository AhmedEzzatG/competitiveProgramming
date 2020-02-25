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

vector<ll> v;
ll gcd(ll a, ll b) {
	return(b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll table;
ll solveMin(int idx = 0, int cnt = 0, ll LCM = 1) {
	if (cnt == 4) return table / LCM * LCM;
	if (idx == sz(v)) return -1;
	return max(solveMin(idx + 1, cnt, LCM),
		solveMin(idx + 1, cnt + 1, lcm(LCM, v[idx])));
}

ll solveMax(int idx = 0, int cnt = 0, ll LCM = 1) {
	if (cnt == 4) return (table + LCM - 1) / LCM * LCM;
	if (idx == sz(v)) return INF;
	return min(solveMax(idx + 1, cnt, LCM),
		solveMax(idx + 1, cnt + 1, lcm(LCM, v[idx])));
}


int main() {
	run();
	int n; 
	while (cin >> n, n) {
		int t;
		cin >> t;
		v = vector<ll>(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		while (t--) {
			cin >> table;
			cout << solveMin() << ' ' << solveMax() << endl;
		}
	}
}