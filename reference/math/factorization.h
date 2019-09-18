#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;
vector<int> divisors[N + 1];
// generate divisors for all number from 1 to n
// O(n*log(n)) // max-> 1e6
void rangeDivisors() {
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j += i)
			divisors[j].push_back(i);
}

// return sum of divisors for all number from 1 to n
//O(n) // max -> 1e8
ll sumRangeDivisors(int n) {
	ll ans = 0;
	for (int x = 1; x <= n; x++)
		ans += (n / x) * x;
	return ans;
}

// return sum of divisors for all number from 1 to n
// max -> 1e9
ll get_sum_div(ll x) {
	ll ans = 0, left = 1, right;
	for (; left <= x; left = right + 1) {
		right = x / (x / left);
		ans += (x / left) * (left + right) * (right - left + 1) / 2;
	}
	return ans;
}
