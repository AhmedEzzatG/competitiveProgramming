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
int n, x;
vector<int> v;
int mem[101][101 * 100];
int solve(int index, int sum) {
	if (index == n)
		return (sum > 50 * 100 ? sum : 100 * 100);
	int& rt = mem[index][sum];
	if (~rt)return rt;
	rt = solve(index + 1, sum + v[index]);
	if (index != x)
		rt = min(rt, solve(index + 1, sum));
	return rt;
}
int main() {
	run();
	cout << fixed << setprecision(2);
	while (cin >> n >> x, n || x) {
		clr(mem, -1);
		x--;
		v = vector<int>(n);
		for (int i = 0; i < n; i++) {
			double d; cin >> d;
			v[i] = d * 100;
		}
		cout << 100.0 * v[x] / solve(0, 0) << endl;
	}
}
