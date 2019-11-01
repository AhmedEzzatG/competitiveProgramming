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
unordered_set<char> mem[MAX][MAX];
char v[3][3], sy[3];
string s;
int index(char ch) {
	return find(sy, sy + 3, ch) - sy;
}

void solve(int l, int r) {
	if (l > r)return;
	if (l == r) {
		mem[l][r].insert(s[l]);
		return;
	}
	unordered_set<char>& rt = mem[l][r];
	if (sz(rt))return;
	for (int k = l; k <= r; k++) {
		solve(l, k);
		solve(k + 1, r);
		for (auto& it1 : mem[l][k])for (auto& it2 : mem[k + 1][r])
			rt.insert(v[index(it1)][index(it2)]);
	}
}

int main() {
	run();
	for (int i = 0; i < 3; i++)
		cin >> sy[i];
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)
		cin >> v[i][j];
	char val;
	cin >> s >> val;
	solve(0, sz(s));
	if (mem[0][sz(s)].find(val) != mem[0][sz(s)].end())
		cout << "yes\n";
	else cout << "no\n";
}
