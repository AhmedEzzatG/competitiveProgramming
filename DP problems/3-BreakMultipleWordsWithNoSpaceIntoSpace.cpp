#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int MAX = 10001;
set<string> dictionary;
vector<string> words, build[MAX];
string word;
int mem[MAX];
int canSplit(int start) {
	if (start == word.size())return 1;
	int& rt = mem[start];
	if (~rt)return rt;
	rt = 0;
	string subWord;
	for (int end = start; end < word.size(); end++) {
		subWord += word[end];
		if (dictionary.find(subWord) != dictionary.end())
			rt |= canSplit(end + 1);
	}
	return rt;
}


void breakWord_oneSolution(int start = 0) {
	if (start == word.size())return;
	string subWord;
	for (int end = start; end < word.size(); end++) {
		subWord += word[end];
		if (dictionary.find(subWord) != dictionary.end() && canSplit(end + 1)) {
			words.push_back(subWord);
			breakWord_oneSolution(end + 1);
			return;
		}
	}
}

void breakWord_manySolution(int start = 0) {
	if (start == word.size())return;
	vector<string>& rt = build[start];
	if (!rt.empty())return;
	string subWord;
	for (int end = start; end < word.size(); end++) {
		subWord += word[end];
		if (dictionary.find(subWord) != dictionary.end() && canSplit(end + 1)) {
			if (end + 1 < word.size()) {
					breakWord_manySolution(end + 1);
					vector<string> tmp = build[end + 1];
					for (auto& it : tmp) it = subWord + ' ' + it;
					rt.insert(rt.end(), tmp.begin(), tmp.end());
				}
				else rt.push_back(subWord);
		}
	}
}
int main() {
	run();
	clr(mem, -1);
	cin >> word;
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		dictionary.insert(s);
	}
	breakWord_oneSolution();
	for (auto it : words)cout << it << ' ';
	cout << endl;
	build[word.size()] = { "" };
	breakWord_manySolution();
	for (auto it : build[0])
		cout << it << endl;
}
