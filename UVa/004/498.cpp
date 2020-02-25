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

vector<ll> input() {
	string s; getline(cin, s);
	if (s.empty())exit(0);
	stringstream ss; ss << s;
	vector<ll> v;
	int a;
	while (ss >> a) v.push_back(a);
	return v;
}

int main() {
	run();
	while (true) {
		vector<ll> c = input(), x = input();
		reverse(all(c));
		for (int i = 0; i < x.size(); i++) {
			ll res = 0, curX = 1;
			for (int j = 0; j < c.size(); j++) {
				res += c[j] * curX;
				curX *= x[i];
			}
			cout << res << " \n"[i + 1 == x.size()];
		}
	}
}