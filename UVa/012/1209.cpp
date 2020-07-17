#include<bits/stdc++.h>
#include<unordered_map>
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

int dif(const string &s) {
	int mn = oo;
	for (int i = 1; i < sz(s); i++)
		mn = min(mn, abs(s[i] - s[i - 1]));
	return mn;
}

bool cmp(const string& a, const string& b) {
	if (dif(a) != dif(b))return dif(a) > dif(b);
	return a < b;
}

int main() {
	run();
	string s;
	while (cin >> s) {
		string ans = s;
		string t = s;
		int cnt = 10;
		while (cnt-- && next_permutation(all(t)))
			if (cmp(t, ans))ans = t;
		t = s;
		cnt = 10;
		while (cnt-- && prev_permutation(all(t)))
			if (cmp(t, ans))ans = t;
		cout << ans << dif(ans) << endl;
	}
}