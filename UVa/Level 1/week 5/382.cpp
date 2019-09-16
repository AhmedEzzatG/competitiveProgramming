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
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x) << " = " << x << endl
#define numOfDigit(x) (int)(floor(1+log10(x)))
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}
int sumDiv(int n) {
	if (n == 1)return 0;
	int sum = 1, i = 2;
	for (; i * i < n; i++) {
		if (n% i == 0)sum += i + n / i;
	}
	if (i* i == n) sum += i;
	return sum;
}
int main() {
	Fast;
	file();
	cout << "PERFECTION OUTPUT\n";
	int n;
	while (cin >> n, n != 0) {
		cout << setw(5) << n;
		cout << "  ";
		int sum = sumDiv(n);
		if (n == sum)cout << "PERFECT";
		else if (n > sum) cout << "DEFICIENT";
		else cout << "ABUNDANT";
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
}
