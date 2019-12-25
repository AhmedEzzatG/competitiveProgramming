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

int n, m, t;
vector<int> v;
vector<vector<vi>> mem;
int solve(int index, int m, int remSize) {
	if (index == sz(v) || m == 0)return 0;
	int& rt = mem[index][m][remSize];
	if (~rt)return rt;
	rt = solve(index + 1, m, remSize);
	rt = max(rt, solve(index, m - 1, t));
	if(v[index] <= remSize)
		rt = max(rt, 1 + solve(index + 1, m, remSize - v[index]));
	return rt;
}

int main() {
	run();
	int c; cin >> c;
	while (c--) {
		cin >> n >> t >> m;
		v = vector<int>(n);
		mem = vector<vector<vi>>(n, vector<vi>(m + 1, vi(t + 1, -1)));
		char ch;
		for (int i = 0; i < n; i++) {
			if (i)cin >> ch;
			cin >> v[i];
		}
		cout << solve(0, m, t) << endl;
		if (c)cout << endl;
	}
}
