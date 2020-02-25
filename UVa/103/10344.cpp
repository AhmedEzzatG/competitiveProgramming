#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);//freopen("output.out", "w", stdout);
#endif
}
vector<int> v(5);
bool out23(int ind, int res) {
	if (ind > 4) return res == 23;
	return (out23(ind + 1, res + v[ind]) ||
		out23(ind + 1, res - v[ind]) ||
		out23(ind + 1, res * v[ind]));
}

int main() {
	run();
	while (cin >> v[0], v[0]) {
		for (int i = 1; i < 5; i++)
			cin >> v[i];
		bool get = 0;
		sort(all(v));
		do {
			if (out23(1, v[0])) {
				get = 1;
				break;
			}
		} while (next_permutation(all(v)));
		if (get)cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
}
