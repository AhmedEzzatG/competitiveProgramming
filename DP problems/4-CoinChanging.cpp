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
vector<int> coins;
vector<vector<int>> mem;
int coinChange(int index, int value) {
	if (value == 0)return 0;
	if (value < 0 || index == sz(coins))return oo;
	int& rt = mem[index][value];
	if (~rt)return rt;
	rt = coinChange(index + 1, value);
	rt = min(rt, 1 + coinChange(index, value - coins[index]));
	return rt;
}
const int MAX = 1000001;
int mem2[MAX];
int coinChange(int value) {
	if (value == 0)return 0;
	if (value < 0)return oo;
	int& rt = mem2[value];
	if (~rt)return rt;
	rt = oo;
	for (auto coin : coins)
		rt = min(rt, 1 + coinChange(value - coin));
	return rt;
}

int main() {
	run();
	clr(mem2, -1);
	int n, value;
	cin >> n >> value;
	mem = vector<vector<int>>(n, vector<int>(value + 1, -1));
	coins.resize(n);
	for (auto& a : coins)cin >> a;
}
