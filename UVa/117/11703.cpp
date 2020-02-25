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

const int MAX = 1e6 + 2;
int mem[MAX];
void add(int& a, int b) {
	if ((a += b) >= 1000000)a -= 1000000;
}
int x(int i) {
	if (i == 0)return 1;
	int& rt = mem[i];
	if (~rt)return rt;
	rt = 0;
	add(rt, x(i - sqrt(i)));
	add(rt, x(log(i)));
	add(rt, x(i * sin(i) * sin(i)));
	return rt;
}
int main() {
	run();
	clr(mem, -1);
	int n;
	while (cin >> n, n != -1) {
		cout << x(n) << endl;
	}
}
