#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}

vector<bool> v;
bool build(int n, int rem) {
	for (int i = n; i > 1; i--) {
		if (rem == i) {
			v[rem] = 1; rem = 0; break;
		}
		else if (rem - i > 1) {
			v[i] = 1; rem -= i;
		}
	}
	return (rem == 0);
}

bool solve(int n, int s) {
	int m = n * (n + 1) / 2;
	if (s < 0 && abs(s) >= m)RT("Impossible");
	else if(s > m)RT("Impossible");
	if ((m - s) % 2 != 0)RT("Impossible");
	int ne = m - s >> 1;
	v = vector<bool>(n + 1);
	if (!build(n, ne))RT("Impossible");
	cout << 1;
	for (int i = 2, j = 0; i <= n; i++) {
		if (v[i])cout << '-';
		else cout << '+';
		cout << i;
	}
	return true;
}

int main() {
	run();
	int n, s;
	cin >> n >> s;
	solve(n, s);
}
