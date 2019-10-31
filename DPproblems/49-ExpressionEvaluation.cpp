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
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int MAX = 15;
unordered_set<int> mem[MAX][MAX];
vector<int> v;
vector<char> op;
void solve(int l, int r) {
	if (l > r)return;
	if (l == r) {
		mem[l][r].insert(v[l]);
		return;
	}
	unordered_set<int>& rt = mem[l][r];
	if (sz(rt))return;
	for (int k = l; k <= r; k++) {
		solve(l, k);
		solve(k + 1, r);
		for (auto& it1 : mem[l][k])for (auto& it2 : mem[k + 1][r]) {
			if (op[k] == '+')
				rt.insert(it1 + it2);
			else if (op[k] == '-')
				rt.insert(it1 - it2);
			else if (op[k] == '*')
				rt.insert(it1 * it2);
			else if (it2 != 0)
				rt.insert(it1 / it2);
		}
	}
}

int main() {
	run();
	string s;
	int val;
	cin >> s >> val;
	v.push_back(s[0] - '0');
	for (int i = 1; i < sz(s); i += 2) {
		op.push_back(s[i]);
		v.push_back(s[i + 1] - '0');
	}
	solve(0, sz(op));
	if (mem[0][sz(op)].find(val) != mem[0][sz(op)].end())
		cout << "yes\n";
	else cout << "no\n";
}
