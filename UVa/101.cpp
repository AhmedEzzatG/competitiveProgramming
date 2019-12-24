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

vector<deque<int>> v;
vector<int> id;
void pop(int a) {
	int i = id[a];
	vector<int> c;
	while (v[i].back() != a) {
		c.push_back(v[i].back()); v[i].pop_back();
	}
	for (auto it : c) v[it].push_back(it), id[it] = it;
}

void move_onto(int a, int b) {
	pop(a); pop(b);
	v[id[a]].pop_back();
	v[id[b]].push_back(a);
	id[a] = id[b];
}

void move_over(int a, int b) {
	pop(a);
	move_onto(a, v[id[b]].back());
}

void pile_onto(int a, int b) {
	pop(b);
	deque<int> q;
	int i = id[a];
	while (v[i].back() != a)
		q.push_front(v[i].back()), v[i].pop_back();
	v[i].pop_back();
	q.push_front(a);
	i = id[b];
	for (auto it : q)
		v[i].push_back(it), id[it] = i;
}

void pile_over(int a, int b) {
	pile_onto(a, v[id[b]].back());
}
int main() {
	run();
	int n; cin >> n;
	v.resize(n); id.resize(n);
	for (int i = 0; i < n; i++)
		id[i] = i, v[i].push_back(i);

	string x, y; int a, b;
	while (cin >> x) {
		if (x == "quit")break;
		cin >> a >> y >> b;
		if (id[a] == id[b])continue;
		if (x == "move") {
			if (y == "onto")move_onto(a, b);
			else move_over(a, b);
		}
		else {
			if (y == "onto")pile_onto(a, b);
			else pile_over(a, b);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << ':';
		for (auto it : v[i])
			cout << ' ' << it;
		cout << endl;
	}
}
