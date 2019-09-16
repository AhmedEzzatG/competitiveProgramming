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

const int MAX = 1001;
int mem[MAX][MAX];
string s;
int editDistance(int start, int end) {
if (start > end)return 0;
int& rt = mem[start][end];
if (~rt) return rt;
rt = (s[start] != s[end]) + editDistance(start + 1, end - 1);
rt = min({ rt, 1 + editDistance(start + 1, end)
  , 1 + editDistance(start, end - 1) });
return rt;
}
int main() {
run();
int t; cin >> t;
for (int I = 1; I <= t; I++) {
  cout << "Case " << I << ": ";
  clr(mem, -1);
  cin >> s;
  cout << editDistance(0, sz(s) - 1) << endl;
}
}
