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

struct LAZY {
	char ch;
	int cntI;
	LAZY() { ch = 'I'; cntI = 0; }
	LAZY operator +=(const char& update) {
		if (update == 'F' || update == 'E') ch = update;
		else if (ch != 'I') ch = (ch == 'F' ? 'E' : 'F');
		else cntI = (cntI + 1 & 1);
		return *this;
	}
	LAZY operator +=(const LAZY& update) {
		if (update.ch == 'I' && update.cntI == 0)
			return *this;
		return *this += update.ch;
	}
};

struct node {
	int cnt[2];
	void update(const LAZY& l) {
		if (l.ch == 'F') cnt[1] += cnt[0], cnt[0] = 0;
		else if (l.ch == 'E') cnt[0] += cnt[1], cnt[1] = 0;
		else if (l.cntI) swap(cnt[0], cnt[1]);
	}
	int getAns() { return cnt[1]; }
};


struct segment_tree {
	int n;
	string s;
	vector<node> tree;
	vector<LAZY> lazy;
	segment_tree(string& s) {
		n = s.size();
		this->s = s;
		tree = vector<node>(n << 2);
		lazy = vector<LAZY>(n << 2);
		build(1, 1, n);
	}
	void update(int from, int to, char val) {
		update(1, 1, n, from + 1, to + 1, val);
	}
	int query(int from, int to) {
		return query(1, 1, n, from + 1, to + 1);
	}
	node merge(node a, node b) {
		node c;
		c.cnt[0] = a.cnt[0] + b.cnt[0];
		c.cnt[1] = a.cnt[1] + b.cnt[1];
		return c;
	}

	void build(int idx, int start, int end) {
		if (start == end) {
			tree[idx].cnt[s[start - 1] - '0']++;
			return;
		}
		int mid = start + end >> 1;
		build(idx << 1, start, mid);
		build(idx << 1 | 1, mid + 1, end);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}

	void propagate(int idx, int start, int end) {
		tree[idx].update(lazy[idx]);
		if (start != end) {
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
		}
		lazy[idx] = LAZY();
	}

	void update(int idx, int start, int end, int from, int to, char val) {
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

	int query(int idx, int start, int end, int from, int to) {
		propagate(idx, start, end);
		if (from <= start && end <= to)return tree[idx].getAns();
		int mid = start + end >> 1;
		if (to <= mid)
			return query(idx << 1, start, mid, from, to);
		else if (mid < from)
			return query(idx << 1 | 1, mid + 1, end, from, to);
		int a = query(idx << 1, start, mid, from, to);
		int b = query(idx << 1 | 1, mid + 1, end, from, to);
		return a + b;
	}
};

int main() {
	run();
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		cout << "Case " << I << ":\n";
		int n; cin >> n;
		string s;
		while (n--) {
			int a; string t;
			cin >> a >> t;
			while (a--)s += t;
		}
		segment_tree seg(s);
		int q; cin >> q;
		int c = 0;
		while (q--) {
			char ch;
			int l, r;
			cin >> ch >> l >> r;
			if (ch == 'S')
				cout << "Q" << ++c << ": " << seg.query(l, r) << endl;
			else seg.update(l, r, ch);
		}
	}
}