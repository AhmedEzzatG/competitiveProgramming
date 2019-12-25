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
	freopen("output.out", "w", stdout);
#else
#endif
}

bool match(string a, string b) {
	return a[0] == b[0] || a[1] == b[1];
}
int main() {
	run();
	vector<string> v(52);
	while (cin >> v[0], v[0] != "#") {
		for (int i = 1; i < 52; i++)cin >> v[i];
		vector<stack<string>> st(52);
		for (int i = 0; i < 52; i++)st[i].push(v[i]);
		for (int i = 0; i < sz(st); i++) {
			int c = -1;
			if (i >= 3 && match(st[i - 3].top(), st[i].top())) {
				st[i - 3].push(st[i].top());
				st[i].pop();
				c = 3;
			}
			else if (i > 0 && match(st[i - 1].top(), st[i].top())) {
				st[i - 1].push(st[i].top());
				st[i].pop();
				c = 1;
			}
			if (st[i].empty())st.erase(st.begin() + i);
			i -= c + 1;
		}
		cout << sz(st) << " pile" << (sz(st) == 1 ? "" : "s") << " remaining:";
		for (auto it : st)
			cout << ' ' << sz(it);
		cout << endl;
	}
}
