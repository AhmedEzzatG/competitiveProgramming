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

const int MAX = 40;
int mem[MAX][MAX];
ll cnt[MAX][MAX];
string s1, s2;
int longestCommonSubsequence(int index1, int index2) {
	if (index1 == sz(s1) || index2 == sz(s2))return 0;
	int& rt = mem[index1][index2];
	if (~rt)return rt;
	if (s1[index1] == s2[index2])
		return rt = 1 + longestCommonSubsequence(index1 + 1, index2 + 1);
	rt = max(rt, longestCommonSubsequence(index1 + 1, index2));
	rt = max(rt, longestCommonSubsequence(index1, index2 + 1));
	return rt;
}

ll count(int index1, int index2) {
	if (index1 == sz(s1) || index2 == sz(s2))return 1;
	ll& rt = cnt[index1][index2];
	if (~rt)return rt;
	rt = 0;
	int cur = longestCommonSubsequence(index1, index2);
	if (s1[index1] == s2[index2]) {
		if (cur == 1 + longestCommonSubsequence(index1 + 1, index2 + 1))
			return rt = count(index1 + 1, index2 + 1);
	}
	if (cur == longestCommonSubsequence(index1 + 1, index2))
		rt += count(index1 + 1, index2);
	if (cur == longestCommonSubsequence(index1, index2 + 1))
		rt += count(index1, index2 + 1);
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	getline(cin, s1);
	for (int I = 1; I <= t; I++) {
		cout << "Case #" << I << ": ";
		clr(mem, -1); clr(cnt, -1);
		getline(cin, s1);
		getline(cin, s2);
		cout << sz(s1) + sz(s2) - longestCommonSubsequence(0, 0) << ' ';
		cout << count(0, 0) << endl;
	}
}
