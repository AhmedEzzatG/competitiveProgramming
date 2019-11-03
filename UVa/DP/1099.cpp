#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
	return __builtin_popcount((unsigned int)a) + __builtin_popcount(a >> 32);
}
#endif
#endif
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
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
int mem[101][1 << 15], v[15], n;
bool getBit(int num, int idx) {
	return (num & (1 << idx));
}

int getSum(int mask) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (getBit(mask, i))sum += v[i];
	return sum;
}

bool solve(int x, int y, int mask) {
	if (__builtin_popcount(mask) == 1)
		return (getSum(mask) == x * y);
	int& rt = mem[x][mask];
	if (~rt)return rt;
	rt = 0;
	for (int subMask = (mask - 1) & mask; subMask > 0 && !rt; subMask = (subMask - 1) & mask) {
		int subMask2 = (mask ^ subMask);
		int sum = getSum(subMask), sum2 = getSum(subMask2);
		if (sum % y == 0 && sum2 % y == 0) {
			int x1 = sum / y;
			rt |= (solve(x1, y, subMask) && solve(x - x1, y, subMask2));
		}
		if (sum % x == 0 && sum2 % x == 0) {
			int y1 = sum / x;
			rt |= (solve(x, y1, subMask) && solve(x, y - y1, subMask2));
		}
	}
	return rt;
}

int main() {
	run();
	int I = 1;
	while (cin >> n, n) {
		cout << "Case " << I++ << ": ";
		clr(mem, -1);
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < n; i++)cin >> v[i];
		int sum = getSum((1 << n) - 1);
		bool b = 1;
		if (sum != x * y) b = 0;
		else b = solve(x, y, (1 << n) - 1);
		if (b)cout << "Yes\n";
		else cout << "No\n";
	}
}