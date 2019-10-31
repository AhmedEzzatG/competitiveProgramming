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

vector<int> v;
const int MAX = 102;
int mem[MAX][MAX][MAX][2];
int solve(int index, int last, int change, bool isRight) {
	if (index == sz(v))return 0;
	int& rt = mem[index][last][change][isRight];
	if (~rt)return rt;
	rt = solve(index + 1, last, change, isRight);
	if (last == sz(v) || (isRight && v[index] < v[last]) || (!isRight && v[index] > v[last])) {
		rt = max(rt, 1 + solve(index + 1, index, change, isRight));
		if (change)
			rt = max(rt, 1 + solve(index + 1, index, change - 1, !isRight));
	}
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	int n, k;
	cin >> n >> k;
	v = vector<int>(n);
	for (auto& it : v)cin >> it;
	cout << solve(0, sz(v), k, 0) << endl;
}
