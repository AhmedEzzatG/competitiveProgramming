#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };

class EmptyTheBox {
public:
	int D, T;
	vector<ll> best[13];
	double mem[1 << 12];
	bool vis[1 << 12];
	int pro(int x) {
		int rt = 0;
		for (int i = 1; i < x && i <= D; i++)
			rt += (x - i <= D);
		return rt;
	}
	int sumMask(ll mask, bool val) {
		int sum = 0;
		for (int i = 0; i < T; i++)
			if (((mask >> i) & 1) == val)
				sum += i + 1;
		return sum;
	}
	double solve(int mask) {
		double &rt = mem[mask];
		if (vis[mask])
			return rt;
		vis[mask] = true;
		int sum = sumMask(mask, 0);
		for (int d1 = 1; d1 <= D; d1++)
			for (int d2 = 1; d2 <= D; d2++) {
				int take = d1 + d2;
				bool play = false;
				for (auto it : best[take])
					if (((ll) mask & it) == 0) {
						play = true;
						rt += solve(mask | it);
						break;
					}
				if (!play)
					rt += sum;
			}
		rt /= (1.0 * D * D);
		return rt;
	}
	double minExpectedPenalty(int D, int T) {
		this->D = D;
		this->T = T;
		ll mn = min(1LL << D + D - 1, (1LL << T) - 1);
		for (ll mask = 1; mask <= mn; mask++) {
			int sum = sumMask(mask, 1);
			if (sum <= D + D)
				best[sum].push_back(mask);
		}
		for (int i = 1; i <= D + D; i++) {
			sort(all(best[i]));
			reverse(all(best[i]));
		}
		return solve(0);

	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer,
		double p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	EmptyTheBox *obj;
	double answer;
	obj = new EmptyTheBox();
	clock_t startTime = clock();
	answer = obj->minExpectedPenalty(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: "
			<< double(endTime - startTime)
					/ CLOCKS_PER_SEC<< " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	double p2;

	{
		// ----- test 0 -----
		p0 = 2;
		p1 = 3;
		p2 = 1.25;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 6;
		p1 = 2;
		p2 = 2.777777777777778;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 6;
		p1 = 10;
		p2 = 16.64572136166177;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 4;
		p1 = 10;
		p2 = 33.489906787872314;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
