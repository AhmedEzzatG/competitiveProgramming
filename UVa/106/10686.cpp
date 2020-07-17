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
	freopen("output.out", "w", stdout);
#else
#endif
}

bool isalpha(char ch) {
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<string, set<string>> category;
		vector<string> categorys(n);
		map<string, int> need, cnt;
		string line, s;
		int w, p;
		for (int i = 0; i < n; i++) {
			cin >> categorys[i] >> w >> p;
			need[categorys[i]] = p;
			while (w--) {
				cin >> s;
				category[s].insert(categorys[i]);
			}
		}
		cin.ignore();
		while (getline(cin, line)) {
			if (line.empty())break;
			for (auto& ch : line)if (!isalpha(ch))ch = ' ';
			stringstream ss(line);
			while (ss >> s) {
				if (category.find(s) == category.end())continue;
				for (auto it : category[s])cnt[it]++;
				category.erase(s);
			}
		}
		vector<string> out;
		for (auto it : categorys)
			if (cnt[it] >= need[it])out.push_back(it);
		if (out.empty())cout << "SQF Problem.";
		else {
			cout << out[0];
			for (int i = 1; i < sz(out); i++)
				cout << ',' << out[i];
		}
		cout << endl;
	}
}