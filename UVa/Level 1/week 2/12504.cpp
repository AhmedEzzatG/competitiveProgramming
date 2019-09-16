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
void stringToMap(string s, map<string, string>& mp) {
	string x, y;
	bool b = 1;
	for (int i = 1; i < sz(s); i++)
		if (s[i] == ':') b = 0;
		else if (s[i] == ',' || s[i] == '}') {
			if (!x.empty() || !y.empty())
				mp[x] = y;
			b= 1,x.clear(), y.clear();
		}
		else if (b) x.push_back(s[i]);
		else y.push_back(s[i]);
}
void out(set<string> st, char ch) {
	if (!st.empty()) {
		cout << ch;
		int cnt = 0;
		for (auto it : st) {
			if (cnt > 0)cout << ",";
			cnt++;
			cout << it;
		}
		cout << endl;
	}
}
int main() {
	Fast;
	file();
	int n; cin >> n;
	cin.ignore();
	while (n--) {
		string old, nw;
		getline(cin, old);
		getline(cin, nw);
		map<string, string> mpO, mpN;
		stringToMap(old, mpO);
		stringToMap(nw, mpN);
		set<string> sp, sm, sd;
		for (auto it : mpO) {
			if (mpN.find(it.first) == mpN.end())
				sm.insert(it.first);
			else if (mpN[it.first] != it.second)
				sd.insert(it.first);
		}
		for (auto it : mpN) {
			if (mpO.find(it.first) == mpO.end())
				sp.insert(it.first);
		}
		if (sp.empty() && sm.empty() && sd.empty())
			cout << "No changes" << endl;
		out(sp, '+');
		out(sm, '-');
		out(sd, '*');
		cout << endl;
	}
}
