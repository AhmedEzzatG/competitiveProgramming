#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#endif
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

int main() {
	run();
	vector<int> v;
	int a, n;
	while (cin >> a)v.push_back(a);
	n = sz(v);
	vector<int> last(n), prev(n, -1);
	int length = 0;
	auto BS = [&](int val) {
		int st = 1, ed = length, md, rt = length;
		while (st <= ed) {
			md = st + ed >> 1;
			if (v[last[md]] >= val)
				ed = md - 1, rt = md;
			else st = md + 1;
		}
		return rt;
	};
	for (int i = 1; i < n; i++) {
		if (v[i] < v[last[0]]) last[0] = i;
		else if (v[i] > v[last[length]]) {
			prev[i] = last[length];
			last[++length] = i;
		}
		else {
			int index = BS(v[i]);
			prev[i] = last[index - 1];
			last[index] = i;
		}
	}
	cout << length + 1 << "\n-\n";
	vector<int> out;
	for (int i = last[length]; i >= 0; i = prev[i])
		out.push_back(v[i]);
	reverse(all(out));
	for (auto it : out)cout << it << endl;
}
