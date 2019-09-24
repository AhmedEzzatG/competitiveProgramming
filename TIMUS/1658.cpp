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
int mem[901][8101];
int solve(int s1, int s2) {
	if (s1 == 0 && s2 == 0)return 0;
	if (s1 < 0 || s2 < 0)return oo;
	int& rt = mem[s1][s2];
	if (~rt)return rt;
	rt = oo;
	for (int i = 0; i < 10; i++)
		rt = min(rt, 1 + solve(s1 - i, s2 - i * i));
	return rt;
}

void build(int s1, int s2) {
	if (s1 == 0 && s2 == 0)return;
	int rt = solve(s1, s2);
	for (int i = 0; i < 10; i++) {
		if (rt == 1 + solve(s1 - i, s2 - i * i)) {
			cout << i;
			build(s1 - i, s2 - i * i);
			return;
		}
	}
}

int main() {
	run();
	clr(mem, -1);
	int t; cin >> t;
	while (t--) {
		int s1, s2;
		cin >> s1 >> s2;
		if (s1 <= 900 && s2 <= 8100 && solve(s1, s2) <= 100)
			build(s1, s2);
		else cout << "No solution";
		cout << endl;
	}
}
