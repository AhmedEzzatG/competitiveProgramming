#include<bits/stdc++.h>
using namespace std;
#define ll long long

// check number is prime or not
// O(sqrt(n))
bool isprime(ll num) {
	if (num == 2) return true;
	if (num < 2 || !(num & 1)) return false;
	for (ll i = 3; i * i <= num; i += 2)
		if (num % i == 0) return false;
	return true;
}

const int N = 1e8;
bool isPrime[N + 1];
vector<int> prime;
// check all numbers from 1 to n prime or not
// O(n*log(log(n)))
void sieve() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i <= N; i += 2) isPrime[i] = false;
	for (int i = 3; i * i <= N; i += 2) {
		if (isPrime[i])
			for (int j = i * i; j <= N; j += i + i)
				isPrime[j] = false;
	}
	prime.push_back(2);
	for (int i = 3; i <= N; i += 2)
		if (isPrime[i]) prime.push_back(i);
}


// generate prime divisors for all number from 1 to n
// O(n*log(n)) // max -> 2e6
const int M = 2e6;
vector<int> primeDivs[M + 1];
void primeDivisors() {
	for (int i = 2; i <= M; i += 2)
		primeDivs[i].push_back(2);
	for (int i = 3; i <= M; i += 2) {
		if (primeDivs[i].empty())
			for (int j = i; j <= M; j += i)
				primeDivs[j].push_back(i);
	}
}
