#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

class BigInt {
	const int BASE = 1000000000;
	vector<int> v;
public:
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
				carry += (ll)v[i] * (j < a.size() ? a.v[j] : 0);
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

const int MAX = 10001;
BigInt mem[MAX];
BigInt catalanNumber(int n) {
	if (n <= 1)return 1;
	BigInt& rt = mem[n];
	if (!rt.zero())return rt;
	for (int i = 0; i < n; i++)
		rt += catalanNumber(i) * catalanNumber(n - i - 1);
	return rt;
}


int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << catalanNumber(n) << endl;
	}
}
