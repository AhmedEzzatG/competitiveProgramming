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
const int MAX = 10009;
int mem[MAX][MAX];
vector<int> v;
int maxDifferentProfit(int left, int right) {
	if (left > right)return 0;
	int& rt = mem[left][right];
	if (~rt)return rt;
	rt = 1 + max(v[left] - maxDifferentProfit(left + 1, right),
		v[right] - maxDifferentProfit(left, right - 1));
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n; cin >> n;
		v.resize(n);
		int sum = 0;
		for (auto& it : v) { cin >> it; sum += it; }
		int dif = maxDifferentProfit(0, sz(v) - 1);
		int p2 = (sum - dif) / 2;
		int p1 = sum - p2;
		cout << p1 << ' ' << p2 << endl;
	}
}
