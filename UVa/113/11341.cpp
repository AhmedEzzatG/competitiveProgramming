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
vector<vector<int>> v;
int mem[11][109];
int solve(int idx, int t) {
	if (idx == sz(v))return 0;
	int &rt = mem[idx][t];
	if (~rt)return rt;
	rt = 0;
	for (int i = 0; i < t; i++) {
		if (v[idx][i] < 5)continue;
		int ch = solve(idx + 1, t - i - 1);
		if (ch >= 5 * (sz(v) - idx - 1))
			rt = max(rt, v[idx][i] + ch);
	}
	return rt;
}

int main() {
	run();
	cout << fixed << setprecision(2);
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n, m;
		cin >> n >> m;
		v = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		double ans = solve(0, m);
		ans = (ans + 1e-3) / n;
		if (ans <= 5 - 1e-3)cout << "Peter, you shouldn't have played billiard that much.\n";
		else cout << "Maximal possible average mark - " << ans << ".\n";
	}
}