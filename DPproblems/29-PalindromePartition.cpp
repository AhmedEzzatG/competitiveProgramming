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
const int MAX = 1001;
int palindrome[MAX][MAX], mem[MAX];
vector<vector<string>> build[MAX];
string s;
int isPalindrome(int left, int right) {
	if (left > right)return 0;
	if (left == right || left + 1 == right)
		return s[left] == s[right];
	int& rt = palindrome[left][right];
	if (~rt)return rt;
	rt = 0;
	if (s[left] == s[right])
		rt = isPalindrome(left + 1, right - 1);
	return rt;
}

int palindromePartition(int start) {
	if (start == sz(s))return 0;
	int& rt = mem[start];
	if (~rt)return rt;
	rt = oo;
	for (int end = start; end < sz(s); end++)
		if (isPalindrome(start, end))
			rt = min(rt, 1 + palindromePartition(end + 1));
	return rt;
}

void palindromePartition_allSolution(int start) {
	if (start == (int)(s.size()))return;
	vector<vector<string>>& rt = build[start];
	if ((int)(rt.size()))return;
	string cur = "";
	for (int end = start; end < (int)(s.size()); end++) {
		cur.push_back(s[end]);
		if (isPalindrome(start, end)) {
			if (end + 1 == s.size())
				rt.push_back(vector<string>(1, cur));
			else {
				palindromePartition_allSolution(end + 1);
				for (auto& it : build[end + 1]) {
					rt.push_back(vector<string>(1, cur));
					rt.back().insert(rt.back().end(), it.begin(), it.end());
				}
			}
		}
	}
}

int main() {
	run();
	clr(mem, -1);
	clr(palindrome, -1);
	cin >> s;
	cout << palindromePartition(0) << endl;
}
