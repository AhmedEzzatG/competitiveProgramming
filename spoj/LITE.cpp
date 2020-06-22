#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

struct node { //implement it
	ll sum = 0;
	static node merge(const node &a, const node &b) {
		node c;
		c.sum = a.sum + b.sum;
		return c;
	}
	template<class updateType>
	void apply(const updateType &val, int start, int end) {
		sum = (end - start + 1 - sum);
	}
	template<class T>
	node& operator =(const T &val) {
		this->sum = val;
		return *this;
	}
};

template<class node, class lazyType> class segment_tree {
#define LEFT (idx<<1)
#define RIGHT (idx<<1|1)
#define MID ((start+end)>>1)
	int n;
	vector<node> tree;
	vector<lazyType> lazy;
	lazyType default_lazy;
	void update_lazy(lazyType &a, const lazyType &b) { //implement it
		a ^= b;
	}
public:
	segment_tree(int n, node val = node(), lazyType default_lazy = lazyType()) {
		this->n = n;
		this->default_lazy = default_lazy;
		tree = vector<node>(n << 2, val);
		lazy = vector<lazyType>(n << 2, default_lazy);
	}
	template<typename T>
	segment_tree(const vector<T> &arr, lazyType default_lazy = lazyType()) {
		this->n = arr.size() - 1;
		this->default_lazy = default_lazy;
		tree = vector<node>(n << 2);
		lazy = vector<lazyType>(n << 2, default_lazy);
		build(1, 1, n, arr);
	}
	void update(int from, int to, const lazyType &val) {
		update(1, 1, n, from, to, val);
	}

	node query(int from, int to) {
		return query(1, 1, n, from, to);
	}
private:
	template<typename T>
	void build(int idx, int start, int end, const vector<T> &arr) {
		if (start == end) {
			tree[idx] = arr[start];
			return;
		}
		build(LEFT, start, MID, arr);
		build(RIGHT, MID + 1, end, arr);
		tree[idx] = node::merge(tree[LEFT], tree[RIGHT]);
	}
	void propagate(int idx, int start, int end) {
		if (lazy[idx] == default_lazy)
			return;
		tree[idx].apply(lazy[idx], start, end);
		if (start != end) {
			update_lazy(lazy[LEFT], lazy[idx]);
			update_lazy(lazy[RIGHT], lazy[idx]);
		}
		lazy[idx] = default_lazy;
	}
	void update(int idx, int start, int end, int from, int to,
			const lazyType &val) {
		propagate(idx, start, end);
		if (to < start || end < from)
			return;
		if (from <= start && end <= to) {
			update_lazy(lazy[idx], val);
			propagate(idx, start, end);
			return;
		}
		update(LEFT, start, MID, from, to, val);
		update(RIGHT, MID + 1, end, from, to, val);
		tree[idx] = node::merge(tree[LEFT], tree[RIGHT]);
	}
	node query(int idx, int start, int end, int from, int to) {
		propagate(idx, start, end);
		if (from <= start && end <= to)
			return tree[idx];
		if (to <= MID)
			return query(LEFT, start, MID, from, to);
		if (MID < from)
			return query(RIGHT, MID + 1, end, from, to);
		return node::merge(query(LEFT, start, MID, from, to),
				query(RIGHT, MID + 1, end, from, to));
	}
#undef LEFT
#undef RIGHT
#undef MID
};

int main() {
	run();
	int n, q;
	cin >> n >> q;
	segment_tree<node, int> seg(n);
	while (q--) {
		int s;
		int l, r;
		cin >> s >> l >> r;
		if (s == 1)
			cout << seg.query(l, r).sum << endl;
		else
			seg.update(l, r, 1);
	}
}