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
const int MAX = 1001;
int mem[MAX][MAX];
string a, b, c;
int isInterleave(int indexA, int indexB, int indexC) {
	if (indexC == (int)(c.size()))return true;
	int rt = mem[indexA][indexC];// indexB is inference variable
	if (~rt)return rt;
	rt = 0;
	if (indexA < (int)(a.size()) && a[indexA] == c[indexC])
		rt |= isInterleave(indexA + 1, indexB, indexC + 1);
	if (indexB < (int)(b.size()) && b[indexB] == c[indexC])
		rt |= isInterleave(indexA, indexB + 1, indexC + 1);
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		cin >> a >> b >> c;
		cout << isInterleave(0, 0, 0) << endl;
	}
}
