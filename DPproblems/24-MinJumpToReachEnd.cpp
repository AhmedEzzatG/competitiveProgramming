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

vector<int> jumps, mem;
int minJumpToReachEnd(int index) {
	if (index + 1 == sz(jumps))return 0;
	int& rt = mem[index];
	if (~rt)return rt;
	rt = oo;
	for (int i = 1; i <= jumps[index] && index + i < sz(jumps); i++)
		rt = min(rt, 1 + minJumpToReachEnd(index + i));
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		jumps = vector<int>(n);
		mem = vector<int>(n + 1, -1);
		for (auto& it : jumps)cin >> it;
		int ans = minJumpToReachEnd(0);
		cout << (ans == oo ? -1 : ans) << endl;
	}
}
