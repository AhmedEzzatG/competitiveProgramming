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

const int MAX = 101;
int mem[MAX][MAX];
vector<int> v1, v2;
int longestCommonSubsequence(int index1, int index2) {
	if (index1 == sz(v1) || index2 == sz(v2))return 0;
	int& rt = mem[index1][index2];
	if (~rt)return rt;
	if (v1[index1] == v2[index2])
		rt = 1 + longestCommonSubsequence(index1 + 1, index2 + 1);
	rt = max(rt, longestCommonSubsequence(index1 + 1, index2));
	rt = max(rt, longestCommonSubsequence(index1, index2 + 1));
	return rt;
}

int main() {
	run();
	int n, m;
	int I = 0;
	while (cin >> n >> m, n || m) {
		cout << "Twin Towers #" << ++I << "\nNumber of Tiles : ";
		clr(mem, -1);
		v1 = vi(n);
		v2 = vi(m);
		for (int i = 0; i < n; i++)cin >> v1[i];
		for (int i = 0; i < m; i++)cin >> v2[i];
		cout << longestCommonSubsequence(0, 0) << endl << endl;
	}
}
