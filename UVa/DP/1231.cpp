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

const int MAX = 2001;
int mem[MAX][MAX][3];
vector<vi> cnt;
int t, h, f;
int maxAcorns(int curTree, int curHight, int d) {
	if (curTree <  0 || curTree >= sz(cnt) || curHight < 0)
		return 0;
	int& rt = mem[curTree][curHight][d + 1];
	if (~rt)return rt;
	rt = 0;
	if (d == 0) {
		rt = cnt[curTree][curHight] + max({ maxAcorns(curTree, curHight - 1, 0),
			maxAcorns(curTree - 1, curHight, -1),maxAcorns(curTree + 1, curHight, 1) });
	}
	else {
		rt = max(maxAcorns(curTree, curHight - f, 0),
			maxAcorns(curTree + d, curHight, d));
	}
	return rt;
}

int main() {
	run();
	int c;
	while (cin >> c, c) {
		while (c--) {
			clr(mem, -1);
			cin >> t >> h >> f;
			cnt = vector<vi>(t, vi(h + 1));
			for (int i = 0; i < t; i++) {
				int m; cin >> m;
				while (m--) {
					int x; cin >> x;
					cnt[i][x]++;
				}
			}
			int ans = 0;
			for (int i = 0; i < t; i++)
				ans = max(ans, maxAcorns(i, h, 0));
			cout << ans << endl;
		}
	}
}
