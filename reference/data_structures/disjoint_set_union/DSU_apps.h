#include"DSU.h"


void Painting_subarrays() {
	struct Query {
		int l, r, c;
		Query(int l, int r, int c) :l(l), r(r), c(c) {}
	};
	int n, q;
	cin >> n >> q;
	DSU uf(n);
	vector<int> ans(n + 1);
	vector<Query> query(q);
	for (int i = 0; i < q; i++)cin >> query[i].l >> query[i].r >> query[i].c;
	reverse(query.begin(), query.end());
	for (auto q : query) {
		int l = q.l, r = q.r, c = q.c;
		for (int cur = uf.find_set(l); cur <= r; cur = uf.find_set(cur)) {
			uf.parent[cur] = cur + 1;
			ans[cur] = c;
		}
	}
}

void RMQ() {
	struct Query {
		int l, r, idx;
		Query(int l, int r, int idx) :l(l), r(r), idx(idx) {}
	};
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	vector<vector<Query>> query(n);
	vector<int> ans(q);
	DSU uf(n);
	for (auto& a : v)cin >> a;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		query[r].push_back(Query(l, r, i));
	}
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && v[st.top()] > v[i]) {
			uf.parent[st.top()] = i;
			st.pop();
		}
		st.push(i);
		for (auto q : query[i])
			ans[q.idx] = v[uf.find_set(q.l)];
	}
}