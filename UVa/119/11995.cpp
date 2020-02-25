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
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
int main() {
	Fast;
	file();
	int n;
	while (cin >> n) {
		queue<int> q;
		stack<int> st;
		priority_queue<int> pq;
		bool isSt = 1, isQ = 1, isPq = 1;
		while (n--) {
			int a, x; cin >> a >> x;
			if (a == 1) q.push(x), pq.push(x), st.push(x);
			else {
				if (isSt) {
					if (!st.empty() && st.top() == x)st.pop();
					else isSt = 0;
				}
				if (isQ) {
					if (!q.empty() && q.front() == x)q.pop();
					else isQ = 0;
				}
				if (isPq) {
					if (!pq.empty() && pq.top() == x)pq.pop();
					else isPq = 0;
				}
			}
		}
		int cnt = isQ + isSt + isPq;
		if (cnt == 0) cout << "impossible" << endl;
		else if (cnt > 1) cout << "not sure" << endl;
		else {
			if (isSt)cout << "stack" << endl;
			else if (isQ) cout << "queue" << endl;
			else cout << "priority queue" << endl;
		}
	}
}
