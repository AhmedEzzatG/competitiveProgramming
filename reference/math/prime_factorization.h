#include<bits/stdc++.h>
#include"elementary.h" //power
#include"primes.h" //sieve
using namespace std;
#define ll long long
typedef vector<pair<ll, int>> primeFactors;

// generate prime divisors in n
// n = p1^x1 * p2^x2 .... pn^xn
// O(sqrt(n)) // max = 1e16
primeFactors prime_factors(ll n) {
	primeFactors p;
	int idx = 0;
	while (!(n <= N && isPrime[n]) && idx < prime.size() && (ll)prime[idx] * prime[idx] <= n) {
		int cnt = 0;
		while (n % prime[idx] == 0)
			n /= prime[idx], cnt++;
		if (cnt) p.push_back({ prime[idx],cnt });
		idx++;
	}
	if (n > 1)p.push_back({ n,1 });
	return p;
}

//return multiplication of tow nember using prime factorization
primeFactors multiplication(primeFactors& a, primeFactors& b) {
	primeFactors rt;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i].first < b[j].first) {
			rt.emplace_back(a[i]);
			i++;
		}
		else if (a[i].first > b[j].first) {
			rt.emplace_back(b[j]);
			j++;
		}
		else {
			rt.emplace_back(a[i].first, a[i].second + b[j].second);
			i++; j++;
		}
	}
	return rt;
}

// return gcd between two number using prime factorization
primeFactors gcd(primeFactors a, primeFactors b) {
	primeFactors gcd;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i].first < b[j].first)i++;
		else if (a[i].first > b[j].first)j++;
		else {
			gcd.push_back({ a[i].first,min(a[i].second,b[j].second) });
			i++; j++;
		}
	}
	return gcd;
}

// return lcm between two number using prime factorization
primeFactors lcm(primeFactors a, primeFactors b) {
	primeFactors lcm;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i].first < b[j].first) {
			lcm.push_back(a[i]); i++;
		}
		else if (a[i].first > b[j].first) {
			lcm.push_back(b[j]); j++;
		}
		else {
			lcm.push_back({ a[i].first, max(a[i].second, b[j].second) });
			i++; j++;
		}
	}
	while (i < a.size()) { lcm.push_back(a[i]); i++; }
	while (j < b.size()) { lcm.push_back(b[j]); j++; }
}

// return number of Divisors(n) using prime factorization
ll numOfDivisors(primeFactors mp) {
	ll cnt = 1;
	for (auto it : mp) cnt *= (it.second + 1);
	return cnt;
}

// return sum of Divisors(n) using prime factorization
ll sumOfDivisors(primeFactors mp) {
	ll sum = 1;
	for (auto it : mp)
		sum *= (power(it.first, it.second + 1) - 1) / (it.first - 1);
	return sum;
}
