#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
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
	//freopen("output.out", "w", stdout);
#else
#endif
}

vector<int> op, num;
set<int> ans;
map<int, bool> vis[40][40];
void solve(int idx, int numOpen, int sum) {
	if (idx == sz(num)) { ans.insert(sum); return; }
	if (vis[idx][numOpen].count(sum))return;
	vis[idx][numOpen][sum] = true;
	int curSum = sum + (numOpen & 1 ? -1 : 1) * op[idx] * num[idx];
	solve(idx + 1, numOpen, curSum);
	if(op[idx] == -1) solve(idx + 1, numOpen + 1, curSum);
	if (numOpen) solve(idx + 1, numOpen - 1, curSum);
}

int main() {
	run();
	string s;
	while (getline(cin, s)) {
		op = num = vector<int>();
		ans.clear();
		for (int i = 0; i < 40; i++)for (int j = 0; j < 40; j++)
			vis[i][j].clear();
		stringstream ss(s);
		char ch; int x;
		ss >> x;
		op.push_back(1);
		num.push_back(x);
		while (ss >> ch >> x) {
			op.push_back(ch == '+' ? 1 : -1);
			num.push_back(x);
		}
		solve(0, 0, 0);
		cout << sz(ans) << endl;
	}
}