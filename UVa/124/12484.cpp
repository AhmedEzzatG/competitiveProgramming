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

ll mem[2][10001];
int main() {
	run();
	int n;
	while (cin >> n) {
		clr(mem, 0);
		vector<ll> v(n);
		for (auto& a : v)cin >> a;
		bool cur = 0;
		for (int len = 1; len < n; len++) {
			cur ^= 1;
			for (int i = 0; i + len < n; i++) {
				int j = i + len;
				if (cur) mem[cur][i] = max(v[i] + mem[cur ^ 1][i + 1], mem[cur ^ 1][i] + v[j]);
				else mem[cur][i] = min(mem[cur ^ 1][i], mem[cur ^ 1][i + 1]);
			}
		}
		cout << mem[cur][0] << endl;
	}
}
