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

int n, k;
vector<int> dis;
vector<vi> mem;
int solve(int cur, int cnt) {
	if (cnt == 0)return dis.back() - dis[cur];
	int& rt = mem[cur][cnt];
	if (~rt)return rt;
	rt = oo;
	for (int end = cur + 1; end < n; end++)
		rt = min(rt, max(dis[end] - dis[cur], solve(end, cnt - 1)));
	return rt;
}

int main() {
	run();
	while (cin >> n >> k) {
		n++;
		dis = vector<int>(n + 1);
		mem = vector<vi>(n + 1, vi(k + 1, -1));
		for (int i = 1; i <= n; i++) {
			cin >> dis[i];
			dis[i] += dis[i - 1];
		}
		cout << solve(0, k) << endl;
	}
}
