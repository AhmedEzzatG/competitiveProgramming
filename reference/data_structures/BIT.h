#include<bits/stdc++.h>
using namespace std;

struct fenwickTree {
	vector<int> BIT;
	int n;
	fenwickTree(int n) :n(n) {
		BIT = vector<int>(n + 1);
	}
	int getAccum(int idx) {
		int sum = 0;
		while (idx) {
			sum += BIT[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	void add(int idx, int val) {
		while (idx <= n) {
			BIT[idx] += val;
			idx += (idx & -idx);
		}
	}
	int getValue(int idx) {
		return getAccum(idx) - getAccum(idx - 1);
	}
	// array must be positive
	int getIdx(int accum) {
		int start = 1, end = (int)BIT.size() - 1, rt = -1;
		while (start <= end) {
			int mid = start + end >> 1;
			int val = getValue(mid);
			if (val >= accum)
				rt = mid, end = mid - 1;
			else start = mid + 1;
		}
		return rt;
	}
};


struct fenwickTree2D {
	vector<vector<int>> BIT;
	void addX(int x, int y, int val) {
		while (x < BIT.size()) {
			addY(x, y, val);
			x += (x & -x);
		}
	}
	void addY(int x, int y, int val) {
		while (y < BIT[x].size()) {
			BIT[x][y] += val;
			y += (y & -y);
		}
	}
};
