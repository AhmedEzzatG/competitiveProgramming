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

class segment_tree {
	int n;
	vector<int> seg;
	void update(int idx, int start, int end, int pos, int val) {
		if (start == end) {
			seg[idx] = val;
			return;
		}
		int mid = start + end >> 1;
		if (pos <= mid) update(idx << 1, start, mid, pos, val);
		else update(idx << 1 | 1, mid + 1, end, pos, val);
		seg[idx] = max(seg[idx << 1], seg[idx << 1 | 1]);
	}
	int query(int idx, int start, int end, int from, int to) {
		if (from <= start && end <= to)return seg[idx];
		int mid = start + end >> 1;
		if (to <= mid)
			return query(idx << 1, start, mid, from, to);
		else if (mid < from)
			return query(idx << 1 | 1, mid + 1, end, from, to);
		int a = query(idx << 1, start, mid, from, to);
		int b = query(idx << 1 | 1, mid + 1, end, from, to);
		return max(a, b);
	}
public:
	segment_tree(int n) :n(n) { seg = vector<int>(4 * n); }
	void update(int pos, int val) {
		update(1, 1, n, pos, val);
	}
	int query(int to) {
		return query(1, 1, n, 1, to);
	}
};

int main() {
	run();
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case " << I << ": ";
		int n, p, q;
		cin >> n >> p >> q;
		n *= n; p++; q++;
		vector<int> v(p), idx(n + 1);
		for (int i = 0; i < p; i++)cin >> v[i];
		for (int i = 1; i <= q; i++) {
			int x; cin >> x;
			idx[x] = i;
		}
		for (int i = 0; i < p; i++) v[i] = idx[v[i]];
		segment_tree seg(q);
		int ans = 0;
		for (int i = 0; i < p; i++) {
			if (v[i] == 0)continue;
			int cur = 1 + (v[i] > 1 ? seg.query(v[i] - 1) : 0);
			ans = max(ans, cur);
			seg.update(v[i], cur);
		}
		cout << ans << endl;
	}
}
