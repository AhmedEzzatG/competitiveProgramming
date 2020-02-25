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
int n, m;
vector<int> x, y;
int mem[1009][1009];
int solve(int i, int j) {
	if (i + 1 == n && j + 1 == m)return 0;
	int& rt = mem[i][j];
	if (~rt)return rt;
	rt = oo;
	if (j + 1 < m) rt = min(rt, x[i] + y[j + 1] - y[j] + solve(i, j + 1));
	if (i + 1 < n) rt = min(rt, y[j] + x[i + 1] - x[i] + solve(i + 1, j));
	return rt;
}

void init(vector<int>& v) {
	sort(v.begin() + 1, v.end());
	for (int i = 1; i < sz(v); i++)
		v[i] += v[i - 1];
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		cin >> n >> m;
		x = vector<int>(n);
		y = vector<int>(m);
		for (int i = 1; i < n; i++)cin >> x[i];
		for (int i = 1; i < m; i++)cin >> y[i];
		init(x); init(y);
		cout << solve(0, 0) << endl;
	}
}
