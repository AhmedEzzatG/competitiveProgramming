#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 1001;
int  mem[MAX][MAX];
vector<vector<int>> cost;
int minCostPath(int r, int c) {
	if (r < 0 || c < 0)return oo;
	if (r == 0 && c == 0)return cost[0][0];
	int& rt = mem[r][c];
	if (~rt)return rt;
	rt = oo;
	rt = min(rt, minCostPath(r - 1, c - 1));
	rt = min(rt, minCostPath(r - 1, c));
	rt = min(rt, minCostPath(r, c - 1));
	rt += cost[r][c];
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	int m, n;
	cin >> m >> n;
	cost = vector<vector<int>>(m, vector<int>(n));
	for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)
		cin >> cost[i][j];
	cout << minCostPath(m - 1, n - 1);
}
