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

bool isChar(char ch) {
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}
int main() {
	Fast;
	file();
	string s;
	set<string> st;
	while (cin >> s) {
		string y;
		for (char& ch : s)
			if (!isChar(ch)) ch = ' ';
			else ch = tolower(ch);
		for (char ch : s) {
			if (ch != ' ') y.push_back(ch);
			else if (!y.empty())
				st.insert(y), y.clear();;
		}
		if (!y.empty())
			st.insert(y), y.clear();;
	}
	for (auto it : st)
		cout << it << endl;
}
