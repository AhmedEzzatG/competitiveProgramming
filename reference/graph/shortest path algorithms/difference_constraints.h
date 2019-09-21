#include"Bellmanford.h"

void  difference_constraints() {
	int m; cin >> m;
	int cnt = 1;
	while (m--) {
		string x1, x2; int w; // x1 - x2 <= w
		cin >> x1 >> x2 >> w;
		map<string, int> id;
		if (id.find(x1) == id.end())
			id[x1] = cnt++;
		if (id.find(x2) == id.end())
			id[x2] = cnt++;
		edgeList.emplace_back(id[x2], id[x1], w);
	}
	for (int i = 1; i < cnt; i++) edgeList.emplace_back(cnt, i, 0);
	bellmanford(cnt, cnt);
}