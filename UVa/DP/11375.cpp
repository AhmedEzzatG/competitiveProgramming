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
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
struct BigInt {
	const int BASE = 1000000000;
	vector<int> v;
	BigInt() {}
	BigInt(int val) { v.push_back(val); }
	bool empty() { return v.empty(); }
	void Mod(int& a) {
		if (a >= BASE)a -= BASE;
	}
	void add(int val, int idx = 0) {
		do {
			if (sz(v) == idx)v.push_back(0);
			v[idx] += val;
			val = v[idx] / BASE;
			Mod(v[idx]);
			idx++;
		} while (val);
	}
	void add(const BigInt& other) {
		int idx = 0, rem = 0;
		for (int i = 0; i < sz(other.v); i++) {
			if (sz(v) == idx)v.push_back(0);
			rem += other.v[i];
			v[idx] += rem;
			rem = v[idx] / BASE;
			Mod(v[idx]);
			idx++;
		}
		if (rem) add(rem, idx);
	}
	void print() {
		cout << v.back();
		for (int j = sz(v) - 2; j >= 0; j--)
			cout << setfill('0') << setw(9) << v[j];
	}
};

const int MAX = 2001;
BigInt mem[MAX][2];
vector<int> need = { 6,2,5,5,4,5,6,3,7,6 };
BigInt countNumbers(int n, bool start = false) {
	if (n < 2) return BigInt(0);
	BigInt& rt = mem[n][start];
	if (!rt.empty())return rt;
	rt.add(0);
	for (int i = start; i < 10; i++)
		if (need[i] <= n) {
			rt.add(1);
			rt.add(countNumbers(n - need[i]));
		}
	return rt;
}

int main() {
	run();
	int n;
	while (cin >> n) {
		BigInt ans = countNumbers(n, 1);
		if (n >= 6)ans.add(1);
		ans.print();
		cout << endl;
	}
}
