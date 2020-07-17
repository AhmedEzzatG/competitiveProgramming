#include<bits/stdc++.h>
#include<unordered_map>
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
	//freopen("output.out", "w", stdout);
#else
#endif
}

string s;
bool find(int i, const string& t) {
	int j = 0;
	while (i + j < sz(s) && j < sz(t) && s[i + j] == t[j]) j++;
	return j == sz(t);
}

void replace(int i, int sz, const string& t) {
	s = s.substr(0, i) + t + s.substr(i + sz);
}

int main() {
	run();
	int n; 
	while (cin >> n, n) {
		cin.ignore();
		vector<pair<string, string>> v(n);
		for (int i = 0; i < n; i++) {
			getline(cin, v[i].first);
			getline(cin, v[i].second);
		}
		getline(cin, s);
		for (int j = 0; j < n; j++) {
			int i = 0;
			while (i < sz(s)) {
				if (find(i, v[j].first))
					replace(i, sz(v[j].first), v[j].second);
				else i++;
			}
		}
		cout << s << endl;
	}
}