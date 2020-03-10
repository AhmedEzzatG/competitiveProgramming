#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

struct BigInt {
	const int BASE = 1000000000;
	vector<int> v;
	BigInt() {
	}
	BigInt(long long val) {
		*this = val;
	}
	int size() const {
		return v.size();
	}
	bool zero() const {
		return v.empty();
	}
	BigInt operator =(const long long &a) {
		v.clear();
		long long val = a;
		while (val) {
			v.push_back(val % BASE);
			val /= BASE;
		}
		return *this;
	}
	BigInt operator =(const BigInt &a) {
		v = a.v;
		return *this;
	}
	bool operator <(const BigInt &a) const {
		if (a.size() != size())
			return size() < a.size();
		for (int i = size() - 1; i >= 0; i--) {
			if (v[i] != a.v[i])
				return v[i] < a.v[i];
		}
		return false;
	}
	bool operator >(const BigInt &a) const {
		return a < *this;
	}
	bool operator ==(const BigInt &a) const {
		return (!(*this < a) && !(a < *this));
	}
	BigInt operator +(const BigInt &a) {
		BigInt b = *this;
		b += a;
		return b;
	}
	BigInt operator +=(const BigInt &a) {
		int idx = 0, carry = 0;
		while (idx < a.size() || carry) {
			if (idx < a.size())
				carry += a.v[idx];
			if (idx == size())
				v.push_back(0);
			v[idx] += carry;
			carry = v[idx] / BASE;
			v[idx] %= BASE;
			idx++;
		}
		return *this;
	}
	BigInt operator *(const BigInt &a) {
		BigInt res;
		if (this->zero() || a.zero())
			return res;
		res.v.resize(size() + a.size());
		for (int i = 0; i < size(); i++) {
			if (v[i] == 0)
				continue;
			ll carry = 0;
			for (int j = 0; carry || j < a.size(); j++) {
				carry += 1LL * v[i] * (j < a.size() ? a.v[j] : 0);
				while (i + j >= res.size())
					res.v.push_back(0);
				carry += res.v[i + j];
				res.v[i + j] = carry % BASE;
				carry /= BASE;
			}
		}
		while (!res.v.empty() && res.v.back() == 0)
			res.v.pop_back();
		return res;
	}
	friend ostream& operator<<(ostream &stream, const BigInt &a) {
		stream << (a.zero() ? 0 : a.v.back());
		for (int i = (int) a.v.size() - 2; i >= 0; i--)
			stream << setfill('0') << setw(9) << a.v[i];
		return stream;
	}
};

const int N = 1009;
BigInt mem[N];
BigInt solve(int n) {
	if (n <= 0)
		return (n == 0);
	BigInt &rt = mem[n];
	if (!rt.zero())
		return rt;
	rt = solve(n - 1) * 2;
	rt += solve(n - 2);
	rt += solve(n - 3);
	return rt;
}

int main() {
	run();
	int n;
	while (cin >> n) {
		cout << solve(n) << endl;
	}
}
