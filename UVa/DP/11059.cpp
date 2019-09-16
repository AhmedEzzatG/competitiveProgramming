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

const int MAX = 20;
ll mem[MAX];
vector<ll> v;
ll maximumProduct(int start) {
	if (start == sz(v))return 0;
	ll& rt = mem[start];
	if (~rt)return rt;
	rt = 0;
	ll product = 1;
	for (int end = start; end < sz(v); end++) {
		product *= v[end];
		rt = max({ rt,product, maximumProduct(end + 1) });
	}
	return rt;
}
int main() {
	run();
	int n;
	int I = 0;
	while (cin >> n) {
		cout << "Case #" << ++I << ": The maximum product is ";
		clr(mem, -1);
		v = vector<ll>(n);
		for (auto& it : v)cin >> it;
		cout << maximumProduct(0) << ".\n\n";
	}
}
