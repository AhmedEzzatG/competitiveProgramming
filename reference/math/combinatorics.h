#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

/*
nCr = n!/((n-r)! * r!)
nPr = n!/(n-r)!
nPr(circle) = nPr/r
*/

ull nCr(int n, int r) {
	if (r > n)return 0;
	ull ans = 1, div = 1, i = r + 1;
	while (i <= n) { ans *= i++; ans /= div++; }
	return ans;
}

ull nPr(int n, int r) {
	if (r > n)return 0;
	ull p = 1, i = n - r + 1;
	while (i <= n) p *= i++;
	return p;
}

// return nCr using pascal triangle
vector<vector<ull>> Pascal;
ull pascalTriangle(int n, int r) {
	if (r > n || n < 0 || r < 0)return 0;
	ull& rt = Pascal[n][r];
	if (rt)return rt;
	if (r == 0 || n == r) return rt = 1;
	rt = pascalTriangle(n - 1, r) + pascalTriangle(n - 1, r - 1);
	return rt;
}


// return catalan number n-th using dp O(n^2)
// catalan[n] = nCr(2n,n)/(n+1) //max = 35
vector<ull> catalan;
ull catalanNumber(int n) {
	if (n <= 1)return 1;
	ull& rt = catalan[n];
	if (rt)return rt;
	for (int i = 0; i < n; i++)
		rt += catalanNumber(i) * catalanNumber(n - i - 1);
	return rt;
}
