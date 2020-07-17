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
	int left, right, mid, sum;
	node& operator=(const int &val) {
		left = right = mid = sum = val;
	}
	int getMax() {
		return max( { left, right, mid, sum });
	}
	static node merge(const node &a, const node &b) {
		node c;
		c.left = max(a.left, a.sum + b.left);
		c.right = max(b.right, b.sum + a.right);
		c.mid = max( { a.mid, b.mid, a.right + b.left });
		c.sum = a.sum + b.sum;
		return c;
	}
};

node tree[1 << 17];
class segment_tree {
#define LEFT (idx<<1)
#define RIGHT (idx<<1|1)
#define MID (start+end>>1)
	int n;
	//vector<node> tree;
public:
	segment_tree(int n, node val = node()) {
		this->n = n;
		//tree = vector<node>(n << 2, val);
	}
	template<typename T>
	segment_tree(const vector<T> &arr) {
		this->n = arr.size() - 1;
		//	tree = vector<node>(n << 2);
		build(1, 1, n, arr);
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
	node query(int idx, int start, int end, int from, int to) {
		if (from <= start && end <= to)
			return tree[idx];
		if (to <= MID)
			return query(LEFT, start, MID, from, to);
		if (MID < from)
			return query(RIGHT, MID + 1, end, from, to);
		node a = query(LEFT, start, MID, from, to);
		node b = query(RIGHT, MID + 1, end, from, to);
		return node::merge(a, b);
	}
#undef LEFT
#undef RIGHT
#undef MID
};

int main() {
	run();
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	segment_tree seg(v);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (r < l)
			swap(l, r);
		cout << seg.query(l, r).getMax() << endl;
	}
}
