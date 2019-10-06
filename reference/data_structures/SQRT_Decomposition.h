#include<bits/stdc++.h>
using namespace std;

int n, sqrtN;
vector<int> v, bucket;
void SQRT_Decomposition() {
	sqrtN = sqrt(n);
	bucket = vector<int>((n + sqrtN - 1) / sqrtN, INT_MAX);
	for (int i = 0; i < n; i++)
		bucket[i / sqrtN] = min(bucket[i / sqrtN], v[i]);
}

int query(int left, int right) {
	int rt = INT_MAX, cur = left;
	while (cur <= right) {
		if (cur % sqrtN == 0 && cur + sqrtN - 1 <= right) {
			rt = min(rt, bucket[cur / sqrtN]);
			cur += sqrtN;
		}
		else {
			rt = min(rt, v[cur]); cur++;
		}
	}

	return rt;
}