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

string a, b;
vector<string> v;

void gen(string s) {
	v.push_back(s);
	if (sz(s) == 6)return;
	for (char ch = 'A'; ch <= 'J'; ch++) {
		if (!s.empty() && abs(s.back() - ch) <= 1)continue;
		gen(s + ch);
	}
}

bool cmp(const string& a, const string& b) {
	if (sz(a) != sz(b))return  sz(a) < sz(b);
	return a < b;
}

int minIdx() {
	int st = 1, ed = sz(v) - 1, ans = sz(v), md;
	while (st <= ed) {
		md = st + ed >> 1;
		if (cmp(a, v[md])) ans = md, ed = md - 1;
		else st = md + 1;
	}
	return ans;
}

int maxIdx() {
	int st = 1, ed = sz(v) - 1, ans = 0, md;
	while (st <= ed) {
		md = st + ed >> 1;
		if (cmp(v[md], b))ans = md, st = md + 1;
		else ed = md - 1;
	}
	return ans;
}

int main() {
	run();
	gen("");
	sort(all(v), cmp);
	while (cin >> a >> b) {
		cout << max(maxIdx() - minIdx() + 1, 0) << endl;
	}
}
