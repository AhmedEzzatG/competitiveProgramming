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
		deque<char> q;
		for (char ch : s) {
			ch = tolower(ch);
			if ('a' <= ch && ch <= 'z') q.push_back(ch);
			else if (!q.empty() && q.back() != ' ')
				q.push_back(' ');
		}
		if (!q.empty() && q.back() == ' ')q.pop_back();
		cout << 1 + count(all(q), ' ') << endl;
	}
}
