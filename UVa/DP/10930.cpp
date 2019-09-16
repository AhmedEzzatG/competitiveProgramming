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
vector<int> v;
vector<vector<int>> mem;
int coinChange(int index, int value) {
	if (value == 0)return 1;
	if (value < 0 || index < 0)return 0;
	int& rt = mem[index][value];
	if (~rt)return rt;
	rt = coinChange(index - 1, value);
	rt |= coinChange(index - 1, value - v[index]);
	return rt;
}


int main() {
	run();
	int I = 1;
	int n;
	while (cin >> n) {
		cout << "Case #" << I++ << ":";
		v = vector<int>(n);
		mem = vector<vi>(n, vi(1001, -1));
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			cout << ' ' << v[i];
		}
		cout << endl;
		bool b = 1;
		for (int i = 0; b && i < n; i++) {
			if (i && v[i - 1] >= v[i])b = 0;
			else if (coinChange(i - 1, v[i]))b = 0;
		}
		if (b) cout << "This is an A-sequence.\n";
		else cout << "This is not an A-sequence.\n";
	}
}
