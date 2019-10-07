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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int MAX = 1001;
int mem[MAX][MAX];
vector<int> sum;
int getSum(int l, int r) {
	return sum[r] - sum[l - 1];
}
int solve(int left, int right) {
	if (left == right)return 0;
	int& rt = mem[left][right];
	if (~rt)return rt;
	if ((right - left) & 1) {
		int mid = left + right >> 1;
		if (getSum(left, mid) == getSum(mid + 1, right))
			return rt = right - left + 1;
	}
	return rt = max(solve(left + 1, right), solve(left, right - 1));
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		string s; cin >> s;
		sum = vector<int>(sz(s) + 1);
		for (int i = 1; i <= sz(s); i++)
			sum[i] = s[i - 1] + sum[i - 1] - '0';
		cout << solve(1, sz(s)) << endl;
	}
}
