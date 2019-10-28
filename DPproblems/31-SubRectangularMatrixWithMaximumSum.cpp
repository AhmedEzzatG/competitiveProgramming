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
const ld PI = acos(-1), EPS = 1e-9;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<ll>> sum(n + 1, vector<ll>(m + 1));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				cin >> sum[i][j];
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1];
				sum[i][j] -= sum[i - 1][j - 1];
			}
		ll mx = sum[1][1];
		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)
			for (int x = i; x <= n; x++) for (int y = j; y <= m; y++) {
				ll s = sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];
				mx = max(mx, s);
			}
		cout << mx << endl;
	}
}
