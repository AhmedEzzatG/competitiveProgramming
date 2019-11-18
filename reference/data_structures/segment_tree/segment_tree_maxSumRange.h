#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
	ll left, right, mid, sum;
	node(ll val = 0) { left = right = mid = sum = val; }
	ll getMax() {
		return max({ left,right,mid,sum });
	}
};

struct segment_tree {
	int n;
	vector<node> tree, arr;

	segment_tree(int n = 0) :n(n) {
		arr = vector<node>(n + 1);
		tree = vector<node>(n << 2);
	}

	segment_tree(vector<node>& _arr) {
		n = _arr.size() - 1;
		tree = vector<node>(n << 2);
		arr = _arr;
		build(1, 1, n);
	}

	void update(int pos, int val) {
		update(1, 1, n, pos, val);
	}

	ll query(int from, int to) {
		return query(1, 1, n, from, to).getMax();
	}

	node merge(node a, node b) {
		node c;
		c.left = max(a.left, a.sum + b.left);
		c.right = max(b.right, b.sum + a.right);
		c.mid = max({ a.mid,b.mid,a.right + b.left });
		c.sum = a.sum + b.sum;
		return c;
	}

	void build(int idx, int start, int end) {
		if (start == end) {
			tree[idx] = arr[start]; return;
		}
		int mid = start + end >> 1;
		build(idx << 1, start, mid);
		build(idx << 1 | 1, mid + 1, end);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}

	void update(int idx, int start, int end, int pos, int val) {
		if (start == end) {
			tree[idx] = val; return;
		}
		int mid = start + end >> 1;
		if (pos <= mid)
			update(idx << 1, start, mid, pos, val);
		else
			update(idx << 1 | 1, mid + 1, end, pos, val);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}

	node query(int idx, int start, int end, int from, int to) {
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