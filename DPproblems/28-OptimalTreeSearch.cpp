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

const int MAX = 251;
int mem[MAX][MAX];
vector<int> sum;
int sumFrq(int left, int right) {
	if (left > right)return 0;
	return sum[right] - (left ? sum[left - 1] : 0);
}

int cost(int left, int right) {
	if (left >= right)return 0;
	int& rt = mem[left][right];
	if (~rt)return rt;
	rt = oo;
	for (int root = left; root <= right; root++) {
		int leftTree = cost(left, root - 1) + sumFrq(left, root - 1);
		int rightTree = cost(root + 1, right) + sumFrq(root + 1, right);
		rt = min(rt, leftTree + rightTree);
	}
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	int n; cin >> n;
	sum = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> sum[i];
		if (i) sum[i] += sum[i - 1];
	}
	cout << cost(0, n - 1) << endl;
}
