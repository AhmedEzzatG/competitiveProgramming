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
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int N = 21;
ll mem[2 * N][2 * N][N][N][2];
int n, r, h;
ll solve(int length, int curHight, int cntPeak, bool up) {
	if (curHight < 0)return 0;
	if (length == 0)return (curHight == 0 && cntPeak == 0);
	ll& rt = mem[length][curHight][cntPeak][h][up];
	if (~rt)return rt;
	rt = solve(length - 1, curHight + 1, cntPeak, 1);
	cntPeak -= (up && curHight == h);
	rt += solve(length - 1, curHight - 1, cntPeak, 0);
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	while (cin >> n >> r >> h) {
		n *= 2;
		cout << solve(n, 0, r, 0) << endl;
	}

}
