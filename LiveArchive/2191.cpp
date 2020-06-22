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

struct node {
	ll val = 0;
	static node merge(const node &a, const node &b) {
		node c;
		c.val = a.val + b.val;
		return c;
	}
	template<typename updateType>
	void apply(const updateType &val) {
		*this = val;
	}
	template<typename T>
	node& operator=(const T &val) {
		this->val = val;
		return *this;
	}
};

template<typename node> class segment_tree {
#define LEFT (idx<<1)
#define RIGHT (idx<<1|1)
#define MID (start+end>>1)
	int n;
	vector<node> tree;
public:
	segment_tree(int n, node val = node()) {
		this->n = n;
		tree = vector<node>(n << 2, val);
	}
	template<typename T>
	segment_tree(const vector<T> &arr) {
		this->n = arr.size() - 1;
		tree = vector<node>(n << 2);
		build(1, 1, n, arr);
	}
	template<typename ... Args>
	void update(int pos, const Args &... args) {
		update(1, 1, n, pos, args...);
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
	template<typename ... Args>
	void update(int idx, int start, int end, int pos, const Args &... args) {
		if (start == end) {
			tree[idx].apply(args...);
			return;
		}
		if (pos <= MID)
			update(LEFT, start, MID, pos, args...);
		else
			update(RIGHT, MID + 1, end, pos, args...);
		tree[idx] = node::merge(tree[LEFT], tree[RIGHT]);
	}
	node query(int idx, int start, int end, int from, int to) {
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
	int n;
	int I = 1;
	while (cin >> n, n) {
		if (I != 1)
			cout << endl;
		cout << "Case " << I++ << ":\n";
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		segment_tree<node> seg(v);
		string s;
		while (cin >> s, s != "END") {
			int x, y;
			cin >> x >> y;
			if (s == "M")
				cout << seg.query(x, y).val << endl;
			else
				seg.update(x, y);
		}
	}
}