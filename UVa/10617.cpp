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
string s;
ll mem[65][65];
ll count(int i, int j) {
	if (j < i)return 0;
	if (i == j)return 1;
	ll& rt = mem[i][j];
	if (~rt)return rt;
	rt = 0;
	if (s[i] == s[j])rt += 1 + count(i + 1, j - 1);
	rt += count(i + 1, j);
	rt += count(i, j - 1);
	rt -= count(i + 1, j - 1);
	return rt;
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		cin >> s;
		cout << count(0, sz(s) - 1) << endl;
	}
}	
