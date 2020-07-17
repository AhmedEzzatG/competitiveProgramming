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
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}

struct node {
	int val;
	node* left;
	node* right;
	node() { val = -1; right = left = NULL; }
	node(int x) :val(x), right(NULL), left(NULL) {}
};

node* root;

bool build(string s, int val) {
	node* cur = root;
	for (char ch : s) {
		if (ch == 'L') {
			if (cur->left == NULL)
				cur->left = new node(-1);
			cur = cur->left;
		}
		else {
			if (cur->right == NULL)
				cur->right = new node(-1);
			cur = cur->right;
		}
	}
	if (cur->val == -1) {
		cur->val = val; return 1;
	}
	return 0;
}

bool bfs() {
	queue<node*> q;
	q.push(root);
	vector<int> v;
	while (!q.empty()) {
		node* cur = q.front(); q.pop();
		if (cur->val == -1) return 0;
		v.push_back(cur->val);
		if (cur->left != NULL)q.push(cur->left);
		if (cur->right != NULL)q.push(cur->right);
	}
	cout << v[0];
	for (int i = 1; i < sz(v); i++)
		cout << ' ' << v[i];
	cout << endl;
	return 1;
}

void clear(node* root) {
	if (root->left != NULL)clear(root->left);
	if (root->right != NULL)clear(root->right);
	delete root;
}

int main() {
	run();
	string s;
	while (cin >> s) {
		root = new node(-1);
		stringstream ss;
		if (s != "()") {
			ss << s;
			while (cin >> s, s != "()") ss << ' ' << s;
		}
		else continue;
		char ch; int x; string d;
		bool b = 1;
		while (ss >> ch >> x >> d) {
			d.pop_back(); d = d.substr(1);
			b &= build(d, x);
		}
		if (!b || !bfs())cout << "not complete\n";
		clear(root);
	}
}