struct edge {
	int from, to, weight;
	edge() { from = to = weight = 0; }
	edge(int from, int to, int weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return  weight > other.weight;
	}
};
