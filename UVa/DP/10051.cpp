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
int mem[501][102];
vector<vi> v;
int opposite(int face) {
	if (face & 1)return face - 1;
	return face + 1;
}

int longestIncreasingSubsequence(int index, int last) {
	if (index == sz(v))return 0;
	int& rt = mem[index][last];
	if (~rt)return rt;
	rt = longestIncreasingSubsequence(index + 1, last);
	for (int i = 0; i < 6; i++) {
		if (last == 101 || v[index][opposite(i)] == last)
			rt = max(rt, 1 + longestIncreasingSubsequence(index + 1, v[index][i]));
	}
	return rt;
}

string s[]{ "front", "back", "left", "right", "top", "bottom" };
void build(int index, int last) {
	if (index == sz(v))return;
	int rt = longestIncreasingSubsequence(index, last);
	if (rt == longestIncreasingSubsequence(index + 1, last)) {
		build(index + 1, last);
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (last == 101 || v[index][opposite(i)] == last) {
			if (rt == 1 + longestIncreasingSubsequence(index + 1, v[index][i])) {
				cout << index + 1 << ' ' << s[opposite(i)] << endl;
				build(index + 1, v[index][i]);
				return;
			}
		}
	}
}
int main() {
	run();
	int n;
	int I = 0;
	while (cin >> n, n) {
		if (I)cout << endl;
		cout << "Case #" << ++I << endl;
		clr(mem, -1);
		v = vector<vi>(n);
		for (int i = 0; i < n; i++) {
			v[i] = vi(6);
			for (int j = 0; j < 6; j++)cin >> v[i][j];
		}
		cout << longestIncreasingSubsequence(0, 101) << endl;
		build(0, 101);
	}
}
