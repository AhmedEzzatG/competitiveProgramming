#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
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

int solve(vector<int>& v) {
	vector<int> st;
	auto BS = [&](int val) {
		int  s = 0, e = sz(st) - 1, md, rt = sz(st) - 1;
		while (s <= e) {
			md = (s + e) >> 1;
			if (st[md] < val)
				e = md - 1, rt = md;
			else s = md + 1;
		}
		return rt;
	};
	for (int i = 0; i < sz(v); i++) {
		if (st.empty() || v[i] <= st.back())
			st.push_back(v[i]);
		else st[BS(v[i])] = v[i];
	}
	return sz(st);
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		vector<pair<int, int>> tmp(n);
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			tmp[i] = { a,-b };
		}
		sort(all(tmp));
		for (int i = 0; i < n; i++) v[i] = -tmp[i].second;
		cout << solve(v) << endl;
	}
}
