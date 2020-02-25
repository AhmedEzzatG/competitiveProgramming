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
int n, sqrtN;
vector<int> v, bucket;
void SQRT_Decomposition() {
	sqrtN = sqrt(n);
	bucket = vector<int>((n + sqrtN - 1) / sqrtN, oo);
	for (int i = 0; i < n; i++)
		bucket[i / sqrtN] = min(bucket[i / sqrtN], v[i]);
}

int query(int left, int right) {
	int rt = oo, cur = left;
	while(cur <= right) {
		if (cur % sqrtN == 0 && cur + sqrtN - 1 <= right) {
			rt = min(rt, bucket[cur / sqrtN]);
			cur += sqrtN;
		}
		else {
			rt = min(rt, v[cur]); cur++;
		}
	}

	return rt;
}

int main() {
	run();
	cin >> n;
	v = vector<int>(n);
	for (auto& it : v)cin >> it;
	SQRT_Decomposition();
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(l, r) << endl;
	}

}
