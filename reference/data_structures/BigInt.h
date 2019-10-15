#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct BigInt {
	const int BASE = 1000000000;
	vector<int> v;
	BigInt() {}
	BigInt(long long val) { *this = val; }
	int size() const { return v.size(); }
	bool zero() const { return v.empty(); }
	void operator =(const long long& a) {
		v.clear();
		long long val = a;
		while (val) {
			v.push_back(val % BASE);
			val /= BASE;
		}
	}
	BigInt operator +(const BigInt& a) {
		BigInt b = *this; b += a;
		return b;
	}
	BigInt operator +=(const BigInt& a) {
		int idx = 0, carry = 0;
		while (idx < a.size() || carry) {
			if (idx < a.size())carry += a.v[idx];
			if (idx == size())v.push_back(0);
			v[idx] += carry;
			carry = v[idx] / BASE;
			v[idx] %= BASE;
			idx++;
		}
		return *this;
	}
	BigInt operator *(const BigInt& a) {
		BigInt res;
		if (this->zero() || a.zero())return res;
		res.v.resize(size() + a.size());
		for (int i = 0; i < size(); i++) {
			if (v[i] == 0)continue;
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
		while (!res.v.empty() && res.v.back() == 0)res.v.pop_back();
		return res;
	}
	friend ostream& operator<<(ostream& stream, const BigInt& a) {
		stream << (a.zero() ? 0 : a.v.back());
		for (int i = (int)a.v.size() - 2; i >= 0; i--)
			stream << setfill('0') << setw(9) << a.v[i];
		return stream;
	}
};
