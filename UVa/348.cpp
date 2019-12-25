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

const int M = 11;
ll mem[M][M];
vector<pair<ll, ll>> v;
ll solve(int i, int j) {
	if (i == j)return 0;
	ll& rt = mem[i][j];
	if (~rt)return rt;
	rt = oo * oo;
	for (int k = i; k < j; k++) {
		rt = min(rt, solve(i, k) + solve(k + 1, j)
		 + v[i].first * v[j].second * v[k].second);

	}
	return rt;
}

int cntP[M], cntA[M];
void build(int i, int j) {
	if (i == j) { cout << 'A' << i + 1; return; }
	ll rt = solve(i, j);
	for (int k = i; k < j; k++)
		if (rt == solve(i, k) + solve(k + 1, j) +
			v[i].first * v[j].second * v[k].second) {
			cout << "(";
			build(i, k);
			cout << " x ";
			build(k + 1, j);
			cout << ")";
			break;
		}
}
int main() {
	run();
	int n;
	int I = 0;
	while (cin >> n, n) {
		clr(mem, -1);
		cout << "Case " << ++I << ": ";
		v = vector<pair<ll, ll>>(n);
		for (auto& it : v)cin >> it.first >> it.second;
		build(0, n - 1);
		cout << endl;
	}
}
