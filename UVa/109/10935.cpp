#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}

int main() {
	Fast;
	file();
	int n;
	while (cin >> n) {
		if (n == 0) return 0;
		deque<int> q(n);
		for (int i = 0; i < n; i++) q[i] = i + 1;
		cout << "Discarded cards:";
		while (sz(q) > 2) {
			cout << " " << q.front() << ",";
			q.pop_front();
			q.push_back(q.front());
			q.pop_front();
		}
		if (sz(q) == 2) { cout << " " << q.front(); q.pop_front(); }
		cout << endl << "Remaining card: ";
		if (sz(q) == 1) cout << q.front();
		cout << endl;
	}
}
