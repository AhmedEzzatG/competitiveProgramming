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

vector<int> tmp(3);
struct node {
	int mx, sumMx;
	node() { mx = sumMx = 0; }
	node operator =(const int& a) {
		mx = a; sumMx = 0;
		return *this;
	}
	node operator +(const node& a) {
		node c;
		c.mx = max(a.mx, mx);
		c.sumMx = max({ a.sumMx,sumMx,a.mx + mx });
		return c;
	}
};

struct segment_tree {
	int n;
	vector<int> lazy, arr;
	vector<node> tree;
	segment_tree(vector<int>& arr) {
		this->arr = arr;
		this->n = sz(arr) - 1;
		lazy = vector<int>(n << 2);
		tree = vector<node>(n << 2);
		build(1, 1, n);
	}
	void update(int pos, int val) {
		update(1, 1, n, pos, val);
	}
	int query(int from, int to) {
		return query(1, 1, n, from, to).sumMx;
	}
	void build(int idx, int start, int end) {
		if (start == end) {
			tree[idx] = arr[start];
			return;
		}
		int mid = start + end >> 1;
		build(idx << 1, start, mid);
		build(idx << 1 | 1, mid + 1, end);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	void update(int idx, int start, int end, int pos, int val) {
		if (start == end) {
			tree[idx] = arr[start] = val;
			return;
		}
		int mid = start + end >> 1;
		if (pos <= mid)
			update(idx << 1, start, mid, pos, val);
		else
			update(idx << 1 | 1, mid + 1, end, pos, val);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	node query(int idx, int start, int end, int from, int to) {
		if (from <= start && end <= to)
			return tree[idx];
		int mid = start + end >> 1;
		if (to <= mid)
			return query(idx << 1, start, mid, from, to);
		if (mid < from)
			return query(idx << 1 | 1, mid + 1, end, from, to);
		node a = query(idx << 1, start, mid, from, to);
		node b = query(idx << 1 | 1, mid + 1, end, from, to);
		return a + b;
	}
};
int main() {
	run();
	int n, q;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++)cin >> v[i];
	segment_tree seg(v);
	cin >> q;
	while (q--) {
		char t;
		int x, y;
		cin >> t >> x >> y;
		if (t == 'U')
			seg.update(x, y);
		else cout << seg.query(x, y) << endl;
	}
}
