#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
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

int inv(int ch) {
	return ch + ((ch & 1) ? -1 : 1);
}

int main() {
	run();
	int t; cin >> t;
	for (int I = 1; I <= t;I++) {
		cout << "Case " << I << ":\n";
		string s; cin >> s;
		for (char& ch : s)
			ch = string("(){}[]<>").find(ch);
		vector<int> ans(sz(s));
		stack<int> st;
		for (int i = sz(s) - 1; i >= 0; i--) {
			if (st.size() && (s[i] & 1) == 0 && s[i] + 1 == s[st.top()]) {
				ans[i] = st.top() - i + 1;
				if (st.top() + 1 < sz(s))
					ans[i] += ans[st.top() + 1];
				st.pop();
			}
			else st.push(i);
		}
		for (int it : ans)cout << it << endl;
	}
}