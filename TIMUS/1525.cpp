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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int solve(int m, vector<int> v) {
	int cur = 0;
	int cnt1 = 0, cnt2 = m -1;
	for (int i = 0; i < sz(v); i++) {
		cur += v[i];
		cnt1 = min(cnt1, cur);
	}
	cnt1 *= -1;
	cur = m - 1;
	for (int i = 0; i < sz(v); i++) {
		cur += v[i];
		cnt2 = max(cnt2, cur);
	}
	cnt2 -= m - 1;
	return max(1, m - cnt1 - cnt2);
}

int main() {
	run();
	int d[3];
	for (int i = 0; i < 3; i++)cin >> d[i];
	string s; cin >> s;
	vector<int> v[3];
	for (char ch : s) {
		if (ch == 'l')v[0].push_back(-1);
		else if (ch == 'r')v[0].push_back(1);
		else if (ch == 'u')v[1].push_back(-1);
		else if (ch == 'd')v[1].push_back(1);
		else if (ch == 'f')v[2].push_back(-1);
		else v[2].push_back(1);
	}
	ll ans = 1;
	for (int i = 0; i < 3; i++)
		ans *= solve(d[i], v[i]);
	cout << ans ;
}