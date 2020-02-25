#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
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
vector<vector<int>> v;
const int N = 39;
int sum[N], cur;
pair<ll, ll> mem[N];
ll gcd(ll a, ll b) { return (b == 0 ? abs(a) : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void simple(pair<ll, ll>& rt) {
	ll g = gcd(rt.first, rt.second);
	rt.first /= g;
	rt.second /= g;
}
pair<ll, ll> mul(pair<ll, ll> a, pair<ll, ll> b) {
	pair<ll, ll> rt(a.first * b.first, a.second * b.second);
	simple(rt);
	return rt;
}
void add(pair<ll, ll>& rt, pair<ll, ll> a) {
	ll lc = lcm(rt.second, a.second);
	rt.first *= lc / rt.second;
	rt.first += lc / a.second * a.first;
	rt.second = lc;
	simple(rt);
}

pair<ll, ll> solve(int idx) {
	if (idx + 1 == sz(v[cur])) {
		pair<ll,ll> rt = { v[cur][idx],sum[idx] };
		simple(rt);
		return rt;
	}
	pair<ll, ll>& rt = mem[idx];
	if (rt != make_pair(0ll, 0ll))return rt;
	rt = { 0,1 };
	add(rt, mul({ sum[idx] - v[cur][idx] , sum[idx] }, solve(idx + 1)));
	add(rt, mul({ v[cur][idx], sum[idx] }, solve(idx + 1)));
	simple(rt);
	return rt;
}

int main() {
	run();
	int n, m;
	int cnt = 0;
	while (cin >> n >> m, n || m) {
		clr(sum, 0);
		v = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			sum[j] += v[i][j];
		}
		for (cur = 0; cur < n; cur++) {
			cnt++;
			cout << solve(0).first << " / " << solve(0).second << endl;
			clr(mem, 0);
		}
	}
}
