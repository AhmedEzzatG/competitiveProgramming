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

int main() {
	run();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> sumX(n + 1, vector<int>(m + 1)), sumY(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++) {
		char ch; cin >> ch;
		sumX[i][j] = sumY[i][j] = (ch == 'X');
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)  for (int j = 1; j <= m; j++) {
		sumX[i][j] += sumX[i - 1][j];
		sumY[i][j] += sumY[i][j - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = min(n, m); k > mx; k--) {
				int x = i + k - 1, y = j + k - 1;
				if (x > n || y > m)continue;
				if (sumX[x][j] - sumX[i - 1][j] == x - i + 1
					&& sumX[x][y] - sumX[i - 1][y] == x - i + 1
					&& sumY[i][y] - sumY[i][j - 1] == y - j + 1
					&& sumY[x][y] - sumY[x][j - 1] == y - j + 1) {
					mx = k;
				}
			}
		}
	}
	cout << mx;
}
