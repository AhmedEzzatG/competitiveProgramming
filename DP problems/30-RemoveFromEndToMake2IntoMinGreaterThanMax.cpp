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
int Min[MAX][MAX], Max[MAX][MAX], mem[MAX][MAX];
vector<int> v;
int minInRange(int left, int right) {
	if (left > right)return oo;
	int& rt = Min[left][right];
	if (~rt)return rt;
	rt = min(v[left], v[right]);
	rt = min(rt, minInRange(left - 1, right - 1));
	return rt;
}

int maxInRange(int left, int right) {
	if (left > right)return -oo;
	int& rt = Max[left][right];
	if (~rt)return rt;
	rt = max(v[left], v[right]);
	rt = max(rt, maxInRange(left - 1, right - 1));
	return rt;
}

int removeFromEnd(int left, int right) {
	int& rt = mem[left][right];
	if (~rt)return rt;
	if (2 * minInRange(left, right) > maxInRange(left, right))
		return rt = 0;
	rt = min(removeFromEnd(left + 1, right),
		removeFromEnd(left, right - 1));
	return rt;
}

int main() {
	run();
	clr(Min, -1);
	clr(Max, -1);
	clr(mem, -1);
	int n; cin >> n;
	v.resize(n);
	for (auto& it : v)cin >> it;
	cout << removeFromEnd(0, sz(v) - 1);
}
