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
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	string s;
	while (getline(cin, s)) {
		bool h = 0;
		deque<char>q;
		stack<char> st;
		for (char ch : s) {
			if (ch == ']' || ch == '[') {
				h = (ch == '[');
				while (!st.empty()) {
					q.push_front(st.top());
					st.pop();
				}
			}
			else {
				if (h) st.push(ch);
				else q.push_back(ch);
			}
		}
		while (!st.empty()) {
			q.push_front(st.top());
			st.pop();
		}
		for (int i = 0; i < sz(q); i++)
			cout << q[i];
		cout << endl;
	}
}
