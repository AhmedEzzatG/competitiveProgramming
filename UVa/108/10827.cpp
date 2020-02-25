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

vector<vi> grid;
int getSum(int startR, int endR, int startC, int endC) {
	if (startC > endC) {
		return getSum(startR, endR, startC, sz(grid) - 1)
			+ getSum(startR, endR, 1, endC);
	}
	if (startR > endR) {
		return getSum(startR, sz(grid) - 1, startC, endC)
			+ getSum(1, endR, startC, endC);
	}
	int sum = grid[endR][endC];
	sum -= grid[startR - 1][endC];
	sum -= grid[endR][startC - 1];
	sum += grid[startR - 1][startC - 1];
	return sum;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		grid = vector<vi>(n + 1, vi(n + 1));
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
			grid[i][j] += grid[i - 1][j];
			grid[i][j] += grid[i][j - 1];
			grid[i][j] -= grid[i - 1][j - 1];
		}
		int ans = -oo;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) for (int l = 1; l <= n; l++)
				ans = max(ans, getSum(i, j, k, l));
		cout << ans << endl;
	}
}
