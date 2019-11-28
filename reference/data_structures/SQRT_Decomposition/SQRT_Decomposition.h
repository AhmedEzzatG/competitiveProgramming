#include<bits/stdc++.h>
using namespace std;

template<typename T, typename Q>
struct node {
	int l, r;
	T lazy;
	node(int l, int r) :l(l), r(r), lazy(0) {}
	void build() {
		//update all bucket using lazy
		//build the bucket
		//clear lazy
	}
	//update all bucket
	void update(T val) {}
	//update range in bucket
	void update(int start, int end, T val) {
		if (start == l && end == r)
			return update(val);
		//rebuild the bucket if need
	}
	//query about all bucket
	Q query() {}
	//query about range in bucket
	Q query(int start, int end) {
		if (start == l && end == r)
			return query();
		//calc
	}
};

template<typename T, typename Q>
struct SQRT_Decomposition {
	int n, sqrtN;
	vector<node<T, Q>> bucket;
	int begin(int idx) { return idx * sqrtN; }
	int end(int idx) { return min(sqrtN * (idx + 1), n) - 1; }
	int which_block(int idx) { return idx / sqrtN; }
	SQRT_Decomposition(int n) {
		this->n = n;
		sqrtN = sqrt(n);
		for (int i = 0; i < n; i += sqrtN) {
			bucket.push_back(node<T, Q>(i, min(i + sqrtN, n) - 1));
			bucket.back().build();
		}
	}
	void update(int left, int right, T val) {
		int st = which_block(left), ed = which_block(right);
		bucket[st].update(left, min(bucket[st].r, right), val);
		if (st != ed)bucket[ed].update(bucket[ed].l, right, val);
		for (int i = st + 1; i < ed; i++)
			bucket[i].update(val);
	}

	Q query(int left, int right) {
		int st = which_block(left), ed = which_block(right);
		Q rt = bucket[st].query(left, min(bucket[st].r, right));
		if (st != ed)rt += bucket[ed].query(bucket[ed].l, right);
		for (int i = st + 1; i < ed; i++)
			rt += bucket[i].query();
		return rt;
	}
};