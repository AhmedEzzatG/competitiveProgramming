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
int sqrtN;
struct query {
	int l, r, qIdx, block;
	query(int l, int r, int qIdx) :
		l(l), r(r), qIdx(qIdx), block(l / sqrtN) {}
	bool operator <(const query& o) const {
		if (block != o.block)
			return block < o.block;
		return r < o.r;
	}
};

const int N = 100009;
int frq[2 * N], cnt[N], mx, curL, curR;
vector<int> v, rt;
vector<query> q;

void add(int index) {
	int& f = frq[v[index] + N];
	cnt[f]--;
	f++;
	cnt[f]++;
	mx = max(mx, f);
}

void remove(int index) {
	int& f = frq[v[index] + N];
	cnt[f]--;
	f--;
	cnt[f]++;
	if (cnt[mx] == 0)mx--;
}

int solve(int l, int r) {
	while (curL > l) add(--curL);
	while (curR < r) add(++curR);
	while (curL < l) remove(curL++);
	while (curR > r) remove(curR--);
	return mx;
}

void MO() {
	rt = vector<int>(q.size());
	mx = curL = curR = 0;
	add(0);
	sort(q.begin(), q.end());
	for (auto it : q)
		rt[it.qIdx] = solve(it.l, it.r);
}

int main() {
	run();
	int n;
	while (cin >> n, n) {
		memset(frq,0,sizeof(frq));
		memset(cnt,0,sizeof(cnt));
		int m; cin >> m;
		sqrtN = sqrt(n);
		q.clear();
		v = vector<int>(n + 1);
		for (int i = 0; i < n; i++)cin >> v[i];
		for (int i = 0; i < m; i++) {
			int l, r; cin >> l >> r;
			q.emplace_back(l - 1, r - 1, i);
		}
		MO();
		for (int i = 0; i < m; i++)
			cout << rt[i] << endl;
	}
}
