#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int tmp[3];
struct node {
	int cnt[3];
	node() { memset(cnt, 0, sizeof(cnt)); }
	node operator +=(const int& a) {
		for (int i = 0; i < 3; i++)
			tmp[i] = cnt[i];
		for (int i = 0; i < 3; i++)
			cnt[(i + a) % 3] = tmp[i];
		return *this;
	}
	node operator +(const node& a) {
		node c;
		for (int i = 0; i < 3; i++)
			c.cnt[i] = cnt[i] + a.cnt[i];
		return c;
	}
};

struct segment_tree {
	int n;
	vector<int> lazy;
	vector<node> tree;
	segment_tree(int n) {
		this->n = n;
		lazy = vector<int>(n << 2);
		tree = vector<node>(n << 2);
		build(1, 1, n);
	}
	void update(int from, int to) {
		update(1, 1, n, from + 1, to + 1);
	}
	int query(int from, int to) {
		return query(1, 1, n, from + 1, to + 1);
	}
	void build(int idx, int start, int end) {
		if (start == end) {
			tree[idx].cnt[0]++;
			return;
		}
		int mid = start + end >> 1;
		build(idx << 1, start, mid);
		build(idx << 1 | 1, mid + 1, end);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	void propagate(int idx, int start, int end) {
		lazy[idx] %= 3;
		if (lazy[idx] == 0)return;
		tree[idx] += lazy[idx];
		if (start != end) {
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	void update(int idx, int start, int end, int from, int to) {
		propagate(idx, start, end);
		if (from > end || to < start)return;
		if (from <= start && end <= to) {
			lazy[idx]++;
			propagate(idx, start, end);
			return;
		}
		int mid = start + end >> 1;
		update(idx << 1, start, mid, from, to);
		update(idx << 1 | 1, mid + 1, end, from, to);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	int query(int idx, int start, int end, int from, int to) {
		propagate(idx, start, end);
		if (from <= start && end <= to)
			return tree[idx].cnt[0];
		int mid = start + end >> 1;
		if (to <= mid)
			return query(idx << 1, start, mid, from, to);
		if (mid < from)
			return query(idx << 1 | 1, mid + 1, end, from, to);
		int a = query(idx << 1, start, mid, from, to);
		int b = query(idx << 1 | 1, mid + 1, end, from, to);
		return a + b;
	}
};
int main() {
	run();
	int n, q;
	cin >> n >> q;
	segment_tree seg(n);
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0)
			seg.update(x, y);
		else cout << seg.query(x, y) << endl;
	}
}
