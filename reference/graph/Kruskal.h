#include"..\data_structures\disjoint_set_union\DSU.h"
#include"edge.h"

vector<edge> edgeList;
//O(m*log(m))
pair<int, vector<edge>> MST_Kruskal(int n) {
	DSU uf(n);
	vector<edge> edges;
	int mstCost = 0;
	sort(edgeList.begin(), edgeList.end());
	for (auto e : edgeList)
		if (uf.union_sets(e.from, e.to)) {
			mstCost += e.weight;
			edges.push_back(e);
		}
	if (edges.size() != n - 1)return { INT_MAX,vector<edge>() };
	return { mstCost,edges };
}

int miniMax(int src, int dest, int n) {
	int max = INT_MIN;
	DSU uf(n);
	sort(edgeList.begin(), edgeList.end());
	for (auto e : edgeList) {
		if (uf.same_set(src, dest))return max;
		uf.union_sets(e.from, e.to);
		max = e.weight;
	}
	return max;
}

//O(m*log(m) + n*n)
pair<int, vector<edge>> SMST_Kruskal(int n) {
	DSU uf(n);
	sort(edgeList.begin(), edgeList.end());
	vector<edge> take, leave;
	int mstCost = 0;
	for (auto e : edgeList)
		if (uf.union_sets(e.from, e.to)) {
			mstCost += e.weight;
			take.push_back(e);
		}
		else leave.push_back(e);
	pair<int, vector<edge>> ret = { INT_MAX,vector<edge>() };
	for (int i = 0; i < take.size(); i++) {
		uf = DSU(n);
		vector<edge> edges;
		mstCost = 0;
		for (int j = 0; j < take.size(); j++) {
			if (i == j)continue;
			uf.union_sets(take[j].from, take[j].to);
			mstCost += take[j].weight;
			edges.push_back(take[j]);
		}
		for (edge e : leave) {
			if (uf.union_sets(e.from, e.to)) {
				mstCost += e.weight;
				edges.push_back(e);
				break;
			}
		}
		if (edges.size() == n - 1 && ret.first < mstCost)
			ret = { mstCost,edges };
	}
	return ret;
}
