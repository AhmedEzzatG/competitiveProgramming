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
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

vector<int> v, output;
const int MAX = 1002;
int mem[MAX][MAX][2];
int longestBitonicSequence(int index, int last, bool increasing) {
	if (index == sz(v))return 0;
	int& rt = mem[index][last][increasing];
	if (~rt)return rt;
	rt = longestBitonicSequence(index + 1, last, increasing);
	if (increasing) {
		if (last == sz(v) || v[index] > v[last])
			rt = max(rt, 1 + longestBitonicSequence(index + 1, index, 1));
	}
	if (last == sz(v) || v[index] < v[last])
		rt = max(rt, 1 + longestBitonicSequence(index + 1, index, 0));
	return rt;
}

void buildSequence(int index, int last, bool increasing) {
	if (index == sz(v))return;
	int rt = longestBitonicSequence(index, last, increasing);

	if (rt == longestBitonicSequence(index + 1, last, increasing)) {
		buildSequence(index + 1, last, increasing);
		return;
	}
	if (increasing && (last == sz(v) || v[index] > v[last])) {
		if (rt == 1 + longestBitonicSequence(index + 1, index, 1)) {
			output.push_back(v[index]);
			buildSequence(index + 1, index, 1);
			return;
		}

	}
	if (last == sz(v) || v[index] < v[last]) {
		if (rt == 1 + longestBitonicSequence(index + 1, index, 0)) {
			output.push_back(v[index]);
			buildSequence(index + 1, index, 0);
			return;
		}
	}
}
int main() {
	run();
	clr(mem, -1);
	int n; cin >> n;
	v.resize(n);
	for (auto& a : v)cin >> a;
	buildSequence(0, sz(v), 1);
	for (auto it : output)cout << it << ' ';
}
