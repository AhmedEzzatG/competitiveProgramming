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
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

ll power(ll x, ll y, ll mod) {
	if (y == 0)return 1;
	if (y == 1)return x % mod;
	ll r = power(x, y >> 1, mod);
	return (((r * r) % mod) * power(x, y & 1, mod)) % mod;
}

int main() {
	run();
	int t;
	while (cin >> t) {
		for (int I = 1; I <= t; I++) {
			int n; cin >> n;
			cout << "Case #" << I << ": " << (n < 3 ? 1 : power(n, n - 2, 2000000011)) << endl;
		}
	}
}
