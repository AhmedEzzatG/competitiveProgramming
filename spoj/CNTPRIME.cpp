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

const int N = 1e6 + 9;
bool isPrime[N];
void sieve() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for (int i = 4; i < N; i += 2)
		isPrime[i] = 0;
	for (int i = 3; i * i < N; i += 2)if (isPrime[i])
		for (int j = i * i; j < N; j += i + i)
			isPrime[j] = 0;
}

struct segment_tree {
	int n;
	vector<int> tree, lazy, arr;
	segment_tree(vector<int>& arr) {
		n = sz(arr) - 1;
		this->arr = arr;
		lazy = tree = vector<int>(n << 2);
		build(1, 1, n);
	}
	void update(int from, int to, int val) {
		update(1, 1, n, from, to, val);
	}
	int query(int from, int to) {
		return query(1, 1, n, from, to);
	}
	void build(int idx, int start, int end) {
		if (start == end) {
			tree[idx] = isPrime[arr[start]];
			return;
		}
		int mid = start + end >> 1;
		build(idx << 1, start, mid);
		build(idx << 1 | 1, mid + 1, end);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	void propagate(int idx, int start, int end) {
		if (lazy[idx] == 0)return;
		tree[idx] = isPrime[lazy[idx]] * (end - start + 1);
		if (start != end) {
			lazy[idx << 1] = lazy[idx];
			lazy[idx << 1 | 1] = lazy[idx];
		}
		lazy[idx] = 0;
	}
	void update(int idx, int start, int end, int from, int to, int val) {
		propagate(idx, start, end);
		if (from > end || to < start)return;
		if (from <= start && end <= to) {
			lazy[idx] = val;
			propagate(idx, start, end);
			return;
		}
		int mid = start + end >> 1;
		update(idx << 1, start, mid, from, to, val);
		update(idx << 1 | 1, mid + 1, end, from, to, val);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	int query(int idx, int start, int end,int from,int to) {
		propagate(idx, start, end);
		if (from <= start && end <= to)
			return tree[idx];
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
	sieve();
	int t; cin >> t;
	for (int I = 1; I <= t;I++) {
		cout << "Case " << I << ":\n";
		int n, q;
		cin >> n >> q;
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		segment_tree seg(v);
		while (q--) {
			int t, x, y;
			cin >> t >> x >> y;
			if (t == 0) {
				int v; cin >> v;
				seg.update(x, y, v);
			}
			else cout << seg.query(x, y) << endl;
		}
	}
}
