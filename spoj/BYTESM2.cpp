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
	//freopen("output.out", "w", stdout);
#else
#endif
}

vector<vector<int>> v;
int mem[109][109];
int solve(int i, int j) {
	if (i == sz(v))return 0;
	if (j == sz(v[0]) || j < 0)return -oo;
	int& rt = mem[i][j];
	if (~rt)return rt;
	rt = solve(i + 1, j - 1);
	rt = max(rt, solve(i + 1, j));
	rt = max(rt, solve(i + 1, j + 1));
	rt += v[i][j];
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n, m;
		cin >> n >> m;
		v = vector<vector<int>>(n + 1, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		int mx = 0;
		for (int i = 0; i < m; i++)mx = max(mx, solve(0, i));
		cout << mx << endl;
	}
}
