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
#define RT(s,v) return cout<<s,v
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
int main() {
	Fast;
	file();
	int t; cin >> t;
	int I = 0;
	while (I < t) {
		cout << "Case " << ++I << ":\n";
		int n; cin >> n;
		char arr[12][12];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '.') {
					for (char ch = 'A'; ch <= 'Z'; ch++) {
						if (i + 1 < n && arr[i + 1][j] == ch
							|| j + 1 < n && arr[i][j + 1] == ch
							|| i - 1 >= 0 && arr[i - 1][j] == ch
							|| j - 1 >= 0 && arr[i][j - 1] == ch)
							continue;
						arr[i][j] = ch;
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << arr[i][j];
			cout << endl;
		}
	}
}
