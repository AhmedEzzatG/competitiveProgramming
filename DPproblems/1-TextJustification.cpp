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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 10001;
int mem[MAX], maxLength;
vector<int> length;
vector<pair<int, int>> output;
int solve(int start) {
	if (start == sz(length))return 0;
	int& rt = mem[start];
	if (~rt)return rt;
	rt = oo;
	int sumlength = 0, cost;
	for (int end = start; end < sz(length); end++) {
		sumlength += (end > start) + length[end];
		cost = (maxLength - sumlength) * (maxLength - sumlength);
		if (sumlength <= maxLength)
			rt = min(rt, cost + solve(end + 1));
		else break;
	}
	return rt;
}

void buildText(int start) {
	if (start == sz(length))return;
	int rt = solve(start);
	int sumLength = 0, cost;
	string curLine;
	for (int end = start; end < sz(length); end++) {
		sumLength += (end > start) + length[end];
		cost = (maxLength - sumLength) * (maxLength - sumLength);
		if (sumLength <= maxLength) {
			if (rt == cost + solve(end + 1)) {
				output.emplace_back(start, end);
				buildText(end + 1);
				return;
			}
		}
		else break;
	}
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n;
		cin >> n;
		length = vector<int>(n);
		for (auto& L : length)cin >> L;
		cin >> maxLength;
		output.clear();
		buildText(0);
		for (int i = 0; i < sz(output); i++)
			cout << output[i].first + 1 << ' ' << output[i].second + 1 << ' ';
		cout << endl;
	}
}
