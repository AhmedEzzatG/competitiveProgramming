#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

map<tuple<int, int, int>, int> mem[160];
void Min(int& a, int b) { a = min(a, b); }
int solve(int c, int n1, int n5, int n10) {
	if (n10 < 0 || n5 < 0 || n1 < 0)return oo;
	if (c == 0)return 0;
	if (mem[c].count({ n1,n5,n10 }))return mem[c][{n1, n5, n10}];
	int& rt = mem[c][{n1, n5, n10}];
	rt = oo;
	Min(rt, 1 + solve(c - 1, n1 + 2, n5    , n10 - 1));
	Min(rt, 4 + solve(c - 1, n1 - 3, n5 + 1, n10 - 1));
	Min(rt, 4 + solve(c - 1, n1 - 3, n5 - 1, n10));
	Min(rt, 2 + solve(c - 1, n1 + 2, n5 - 2, n10));
	Min(rt, 8 + solve(c - 1, n1 - 8, n5    , n10));
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int c, n1, n5, n10;
		cin >> c >> n1 >> n5 >> n10;
		cout << solve(c, n1, n5, n10) << endl;
	}
}