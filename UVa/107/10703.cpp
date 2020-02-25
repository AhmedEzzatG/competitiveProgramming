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
#define allr(s) s.rbegin(), s.rend()
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

int arr[550][550];
int main() {
	file();
	int w, h, n;
	while (cin >> w >> h >> n) {
		if (!w && !h && !n) return 0;
		memset(arr, 0, sizeof(arr));
		while (n--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			arr[x1][y1]++;
			arr[x1][y2 + 1]--;
			arr[x2 + 1][y1]--;
			arr[x2 + 1][y2 + 1]++;
		}
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		int cnt = 0;
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				if (arr[i][j] == 0)cnt++;
		if (cnt == 0) cout << "There is no empty spots.\n";
		else if (cnt == 1) cout << "There is one empty spot.\n";
		else printf("There are %d empty spots.\n", cnt);
	}
}
