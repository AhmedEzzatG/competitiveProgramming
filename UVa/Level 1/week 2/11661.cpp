#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(), s.rend()
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	int n;
	while (cin >> n) {
		if (!n) return 0;
		string s; cin >> s;
		if (s.find('Z') != string::npos)
			cout << 0 << endl;
		else {
			int mn = INT_MAX;
			stack<int> r, d;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'R') {
					r.push(i);
					if (!d.empty()) mn = min(mn, abs(d.top() - r.top()));
				}
				else if (s[i] == 'D') {
					d.push(i);
					if (!r.empty()) mn = min(mn, abs(d.top() - r.top()));
				}
			}
			cout << mn << endl;
		}
	}
}
