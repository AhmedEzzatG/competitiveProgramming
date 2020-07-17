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

int n, m;
vector<ll> v;
ll mem[1001][1001];
ll solve(int idx, int k) {
	if (k == 0)return 1;
	if (idx >= n - (k - 1))return 0;
	ll& rt = mem[idx][k];
	if (~rt)return rt;
	return rt = (((v[idx] * solve(idx + 1, k - 1)) % m) + solve(idx + 1, k)) % m;
}

int main() {
	run();
	while (cin >> n >> m, n || m) {
		clr(mem, -1);
		v = vector<ll>(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		ll mx = 0;
		for (int k = n; k > 0; k--)
			mx = max(mx, solve(0, k));
		cout << mx << endl;
	}
}