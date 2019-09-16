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
#define allr(s) s.rbegin(),s.rend()
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
	while (cin >> n, n) {
		int a;
		while (cin >> a) {
			if (!a) { cout << endl; break; }
			vector<int> v(n);
			v[0] = a;
			for (int i = 1; i < n; i++)cin >> v[i];
			stack<int> st;
			int c = 1, i = 0;
			while (c <= n) {
				st.push(c);
				c++;
				while (!st.empty() && st.top() == v[i]) {
					st.pop();
					i++;
					if (i >= n) break;
				}
			}
			cout << (st.empty() ? "Yes" : "No") << endl;
		}
	}
}
