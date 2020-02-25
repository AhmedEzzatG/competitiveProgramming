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

string con(stack<string>& st) {
	string s[3];
	int n = 3;
	while (n--) {
		s[n] = st.top();
		st.pop();
	}
	st.pop();
	string y = s[0] + s[2] + s[1];
	return y;
}
int main() {
	Fast;
	file();
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		stack<string> st;
		for (int i = 0; i < sz(s); i++) {
			string y;
			if (s[i] == ')') y = con(st);
			else y.push_back(s[i]);
			st.push(y);
		}
		while (!st.empty()) {
			cout << st.top() << endl;
			st.pop();
		}
	}
}
