#include <bits/stdc++.h>
using namespace std;
vector<int> v, lg;
vector<vector<int>> sparseTable;

bool isPowerOfTwo(int num) { return (num & num - 1) == 0; }

int Min(int idx1, int idx2) {
	return (v[idx1] <= v[idx2] ? idx1 : idx2);
}

// O(n * log(n))
void buildSparesTable() {
	int n = v.size();
	lg = vector<int>(n + 1);

	// to get log2 in O(1)
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i - 1];
		if (isPowerOfTwo(i)) lg[i]++;
	}
	int logN = lg[n];
	sparseTable = vector<vector<int>>(n, vector<int>(logN + 1));
	for (int i = 0; i < n; i++) sparseTable[i][0] = i;
	for (int k = 1; k <= logN; k++)
		for (int i = 0; i + (1 << k - 1) < n; i++) {
			sparseTable[i][k] = Min(sparseTable[i][k - 1],
				sparseTable[i + (1 << k - 1)][k - 1]);
		}

}

// O(1)
int rangeMinimumQuery(int l, int r) {
	int k = lg[r - l + 1];// max k ==> 2^k <= lenth of range
	//check first 2^k from left ans last 2^k from right //overlap
	return Min(sparseTable[l][k], sparseTable[r - (1 << k) + 1][k]);
}