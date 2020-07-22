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

class HLD {
	int n, is_value_in_edge;
	vector<int> parent, depth, heavy, root, pos_in_array;
	const static int merge(int a, int b) {
		return max(a, b);
	}
	struct array_ds {
		int n;
		vector<int> interval;
		array_ds(int n) :
				n(n), interval(n << 2) {
		}
		void update(int idx, int start, int end, int pos, int value) {
			if (start == end) {
				interval[idx] = value;
				return;
			}
			int mid = (start + end >> 1);
			if (pos <= mid)
				update(idx << 1, start, mid, pos, value);
			else
				update(idx << 1 | 1, mid + 1, end, pos, value);
			interval[idx] = merge(interval[idx << 1], interval[idx << 1 | 1]);
		}
		int query(int idx, int start, int end, int l, int r) {
			if (r < start || l > end)
				return 0;
			if (l <= start && end <= r)
				return interval[idx];
			int mid = (start + end >> 1);
			return merge(query(idx << 1, start, mid, l, r),
					query(idx << 1 | 1, mid + 1, end, l, r));
		}
		void update(int pos, int value) {
			update(1, 0, n - 1, pos, value);
		}
		int query(int l, int r) {
			return query(1, 0, n - 1, l, r);
		}
	} seg;
	struct TREE {
		int cnt_edges = 0;
		vector<vector<int>> adj;
		vector<vector<int>> edge_idx;
		vector<int> edge_to, edge_cost;
		TREE(int n) :
				adj(n), edge_idx(n), edge_to(n), edge_cost(n) {
		}
		void add_edge(int u, int v, int c) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			edge_idx[u].push_back(cnt_edges);
			edge_idx[v].push_back(cnt_edges);
			edge_cost[cnt_edges] = c;
			cnt_edges++;
		}
	} tree;
	int dfs_hld(int node) {
		int size = 1, max_sub_tree = 0;
		for (int i = 0; i < (int) tree.adj[node].size(); i++) {
			int ch = tree.adj[node][i], edge_idx = tree.edge_idx[node][i];
			if (ch != parent[node]) {
				tree.edge_to[edge_idx] = ch;
				parent[ch] = node;
				depth[ch] = depth[node] + 1;
				int child_size = dfs_hld(ch);
				if (child_size > max_sub_tree)
					heavy[node] = ch, max_sub_tree = child_size;
				size += child_size;
			}
		}
		return size;
	}
public:
	HLD(int n, bool is_value_in_edge) :
			n(n), is_value_in_edge(is_value_in_edge), seg(n), tree(n) {
		heavy = vector<int>(n, -1);
		parent = depth = root = pos_in_array = vector<int>(n);
	}
	void add_edge(int u, int v, int c) {
		tree.add_edge(u, v, c);
	}
	void build_chains() {
		parent[0] = -1;
		dfs_hld(0);
		int chain_root = 0, pos = 0;
		while (chain_root < n) {
			if (parent[chain_root] == -1
					|| heavy[parent[chain_root]] != chain_root)
				for (int j = chain_root; j != -1; j = heavy[j]) {
					root[j] = chain_root;
					pos_in_array[j] = pos++;
				}
			chain_root++;
		}
		if (is_value_in_edge)
			for (int i = 0; i < n - 1; i++)
				update_edge(i, tree.edge_cost[i]);
	}
	void update_node(int node, int value) {
		seg.update(pos_in_array[node], value);
	}
	void update_edge(int edge_idx, int value) {
		update_node(tree.edge_to[edge_idx], value);
	}
	int query_in_path(int u, int v) {
		int query_res = 0;
		while (root[u] != root[v]) {
			if (depth[root[u]] > depth[root[v]])
				swap(u, v);
			query_res = merge(query_res,
					seg.query(pos_in_array[root[v]], pos_in_array[v]));
			v = parent[root[v]];
		}
		if (depth[u] > depth[v])
			swap(u, v);
		if (!is_value_in_edge || u != v)
			query_res = merge(query_res,
					seg.query(pos_in_array[u] + is_value_in_edge,
							pos_in_array[v]));
		return query_res;
	}
};

void solve() {
	int n;
	cin >> n;
	HLD hld(n, 1);
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		hld.add_edge(u - 1, v - 1, c);
	}
	hld.build_chains();
	string s;
	while (cin >> s, s != "DONE") {
		int u, v;
		cin >> u >> v;
		if (s == "QUERY")
			cout << hld.query_in_path(u - 1, v - 1) << endl;
		else
			hld.update_edge(u - 1, v);
	}
}

int main() {
	run();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
