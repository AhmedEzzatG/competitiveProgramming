#include<bits/stdc++.h>
using namespace std;

int sqrtN;
struct query {
	int l, r, qIdx, block;
	query(int l, int r, int qIdx) :
		l(l), r(r), qIdx(qIdx), block(l / sqrtN) {}
	bool operator <(const query& o) const {
		if (block != o.block)
			return block < o.block;
		return r < o.r;
	}
};

int curL, curR, ans;
vector<query> q;
vector<int> rt;
void add(int index) {}

void remove(int index) {}

int solve(int l, int r) {
	while (curL > l) add(--curL);
	while (curR < r) add(++curR);
	while (curL < l) remove(curL++);
	while (curR > r) remove(curR--);
	return ans;
}

void MO(int n) {
	sqrtN = sqrt(n);
	rt = vector<int>(q.size());
	ans = curL = curR = 0;
	add(0);
	sort(q.begin(), q.end());
	for (auto it : q)
		rt[it.qIdx] = solve(it.l, it.r);
}
