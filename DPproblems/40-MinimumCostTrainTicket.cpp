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
typedef vector<vector<int>> matrix;
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
vector<vector<int>> v;
vector<int> mem;
int solve(int i) {
	if (i == sz(v)) return 0;
	int& rt = mem[i];
	if (rt != oo) return rt;
	for (int j = i + 1; j < sz(v); j++)
		rt = min(rt, v[i][j] + solve(j));
	return rt;
}

int main() {
	run();
	int n; cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	mem = vector<int>(n + 1, oo);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> v[i][j];
	cout << solve(0);
}
