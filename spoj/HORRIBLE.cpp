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

template<class node>
struct segment_tree {
	int n;
	vector<node> tree, lazy;

	segment_tree(int n = 0) :n(n) {
		lazy = tree = vector<node>(4 * n);
	}

	void update(int from, int to, node val) {
		update(1, 1, n, from, to, val);
	}

	node query(int from, int to) {
		return query(1, 1, n, from, to);
	}

	node merge(node a, node b) {
		return a + b;
	}

	void propagate(int idx, int start, int end) {
		if (lazy[idx] == 0) return;
		tree[idx] += lazy[idx] * (end - start + 1);
		if (start != end) {
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	void update(int idx, int start, int end, int from, int to, node val) {
		propagate(idx, start, end);
		if (to < start || end < from)return;
		if (from <= start && end <= to) {
			lazy[idx] += val;
			propagate(idx, start, end);
			return;
		}
		int mid = start + end >> 1;
		update(idx << 1, start, mid, from, to, val);
		update(idx << 1 | 1, mid + 1, end, from, to, val);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}

	node query(int idx, int start, int end, int from, int to) {
		propagate(idx, start, end);
		if (from <= start && end <= to)return tree[idx];
		int mid = start + end >> 1;
		if (to <= mid)
			return query(idx << 1, start, mid, from, to);
		else if (mid < from)
			return query(idx << 1 | 1, mid + 1, end, from, to);
		node a = query(idx << 1, start, mid, from, to);
		node b = query(idx << 1 | 1, mid + 1, end, from, to);
		return merge(a, b);
	}
};

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		segment_tree<ll> seg(n);
		while (q--) {
			int type, l, r, val;
			cin >> type >> l >> r;
			if (type == 0) {
				cin >> val;
				seg.update(l, r, val);
			}
			else
				cout << seg.query(l, r) << endl;
		}
	}
}
