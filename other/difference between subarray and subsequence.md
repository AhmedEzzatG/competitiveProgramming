# Subarray

A subarray is contiguous part of array (consecutive positions).
for example the subarrays of array {1,2,3} are {1},{1,2},{1,2,3},{2},{2,3},and {3}.

for any array of size n, there n\*(n+1)/2 non-empty subarray.

# How to generate all subarrays?

We can run three nested loops, the first loop picks starting element , second loop picked the ending element of subarray, and the third loop we can print the subarray or do any thing on it.

```cpp
int arr[100];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int start = 0; start < n; start++) {
		for (int last = start; last < n; last++) {
			cout << "subarray from " << start << " to " << last << " : ";
			for (int k = start; k <= last; k++)
				cout << arr[k] << " ";
			cout << endl;
		}
	}
}
```

# Subsequence

A subsequence is a sequence that can be derived from another sequence by deleting zero or more elements, without changing the order of the remaining elements.
for example subsequence of the sequence {1,2,3,4} are {1}, {2},{3},{4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4},{1,2,3},{1,2,4},{1,3,4},{2,3,4},{1,2,3,4}.

More generally, we can say that for a sequence of size n, we have ($2^n$ - 1) non-empty sub-sequences in total.
