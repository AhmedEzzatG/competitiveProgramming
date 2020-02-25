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

struct segment_tree {
	int n;
	vector<int> tree;
	segment_tree(int n) {
		this->n = n;
		tree = vector<int>(n << 2, INT_MAX);
	}
	void update(int pos, int val) {
		update(1, 1, n, pos, val);
	}
	int query(int from, int to) {
		return query(1, 1, n, from, to);
	}
	void update(int idx, int start, int end, int pos, int val) {
		if (start == end) {
			tree[idx] = val;
			return;
		}
		int mid = start + end >> 1;
		if (pos <= mid)
			update(idx << 1, start, mid, pos, val);
		else
			update(idx << 1 | 1, mid + 1, end, pos, val);
		tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
	}
	int query(int idx, int start, int end, int from, int to) {
		if (from <= start && end <= to)
			return tree[idx];
		int mid = start + end >> 1;
		if (to <= mid)
			return query(idx << 1, start, mid, from, to);
		if (mid < from)
			return query(idx << 1 | 1, mid + 1, end, from, to);
		int a = query(idx << 1, start, mid, from, to);
		int b = query(idx << 1 | 1, mid + 1, end, from, to);
		return min(a, b);
	}
};
int main() {
	run();
	int n, q;
	while (cin >> n >> q) {
		vector<int>v(n + 1);
		segment_tree seg(n);
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			seg.update(i, a);
		}
		while (q--) {
			string s; cin >> s;
			for (auto& ch : s)if (ch == '(' || ch == ')' || ch == ',')
				ch = ' ';
			stringstream ss(s);
			ss >> s;
			if (s == "query") {
				int l, r;
				ss >> l >> r;
				cout << seg.query(l, r) << endl;
			}
			else {
				vector<int> v; int a;
				while (ss >> a) v.push_back(a);
				int val = seg.query(v[0], v[0]);
				for (int i = 0; i + 1 < sz(v); i++)
					seg.update(v[i], seg.query(v[i + 1], v[i + 1]));
				seg.update(v.back(), val);
			}
		}
	}
}