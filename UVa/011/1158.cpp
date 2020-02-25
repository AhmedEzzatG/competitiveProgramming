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

const int MAX = 400000;
int mem[MAX + 1];
vector<int> v;
int coinChange(int value) {
if (value == 0)return 0;
if (value < 0)return oo;
int& rt = mem[value];
if (~rt)return rt;
rt = oo;
for (int coin : v) {
  if (coin > value)break;
  rt = min(rt, 1 + coinChange(value - coin));
}
return rt;
}

ll sum(int n) {
return	1LL * n * (n + 1) * (2 * n + 1) / 6;
}
int main() {
run();
clr(mem, -1);
for (int i = 1; i <= MAX; i++) {
  if (sum(i) > MAX)break;
  v.push_back(sum(i));
  if (i * i * i <= MAX)v.push_back(i * i * i);
}
sort(all(v));
int n;
while (cin >> n, ~n) {
  cout << coinChange(n) << endl;
}
}
