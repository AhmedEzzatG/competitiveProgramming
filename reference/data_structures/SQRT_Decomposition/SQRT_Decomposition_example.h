#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
vector<ll> h;
struct node {
	vector<ll> v, sum;
	ll lazy, totalSum;
	int l, r;
	node(int l, int r) :l(l), r(r) {
		lazy = totalSum = 0;
	}
	void build() {
		v.clear(); sum.clear();
		for (int i = l; i <= r; i++) {
			h[i] = max(0LL, h[i] - lazy);
			v.push_back(h[i]);
		}
		sort(all(v));
		sum.push_back(0);
		for (int i = 0; i < sz(v); i++)
			sum.push_back(sum.back() + v[i]);
		lazy = 0; totalSum = sum.back();
	}
	void update(ll val) {
		lazy += val;
		int j = upper_bound(all(v), lazy) - v.begin();
		totalSum = sum.back() - sum[j] - (sz(v) - j) * lazy;
	}
	void update(int start, int end, ll val) {
		for (int i = start; i <= end; i++)
			h[i] = max(0LL, h[i] - val);
		build();
	}
	ll query(int start, int end) {
		ll sum = 0;
		for (int i = start; i <= end; i++)
			sum += max(h[i] - lazy, 0LL);
		return sum;
	}
};

int n, sqrtN;
vector<node> bucket;
void SQRT_Decomposition() {
	sqrtN = sqrt(n);
	for (int i = 0; i < n; i += sqrtN) {
		bucket.push_back(node(i, min(i + sqrtN - 1, n - 1)));
		bucket.back().build();
	}
}

void update(int left, int right, ll val) {
	int cur = left;
	while (cur <= right) {
		if (cur % sqrtN == 0 && cur + sqrtN - 1 <= right)
			bucket[cur / sqrtN].update(val), cur += sqrtN;
		else {
			int endOfBucket = min(right, bucket[cur / sqrtN].r);
			bucket[cur / sqrtN].update(cur, endOfBucket, val);
			cur = endOfBucket + 1;
		}
	}
}

ll query(int left, int right) {
	int cur = left;
	ll rt = 0;
	while (cur <= right) {
		if (cur % sqrtN == 0 && cur + sqrtN - 1 <= right)
			rt += bucket[cur / sqrtN].totalSum, cur += sqrtN;
		else {
			int endOfBucket = min(right, bucket[cur / sqrtN].r);
			rt += bucket[cur / sqrtN].query(cur, endOfBucket);
			cur = endOfBucket + 1;
		}
	}
	return rt;
}
