#include<bits/stdc++.h>
using namespace std;

template<class node>
struct segment_tree {
	int n;
	vector<node> tree, lazy, arr;

	segment_tree(int n = 0) :n(n) { 
		arr = vector<node>(n);
		lazy = tree = vector<node>(4 * n); 
	}

	segment_tree(vector<node>& _arr) {
		n = _arr.size() - 1;
		lazy = tree = vector<node>(4 * n);
		arr = _arr;
		build(1, 1, n);
	}

	void update(int from, int to, node val) {
		update(1, 1, n, from, to, val);
	}

	node query(int from, int to) {
		return query(1, 1, n, from, to);
	}

	node merge(node a, node b);

	void build(int idx, int start, int end) {
		if (start == end) {
			tree[idx] = arr[start]; return;
		}
		int mid = start + end >> 1;
		build(idx << 1, start, mid);
		build(idx << 1 | 1, mid + 1, end);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}

	void propagate(int idx, int start, int end) {
		if (lazy[idx] == 0) return;
		tree[idx] += lazy[idx];
		if (start != end) {
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
		}
		lazy[idx] = 0;

	}

	void update(int idx, int start, int end, int from, int to, node val) {
		if (to < start || end < from)return;
		if (from <= start && end <= to) {
			lazy[idx] += val; return;
		}
		int mid = start + end >> 1;
		propagate(idx, start, end);
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