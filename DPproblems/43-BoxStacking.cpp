{
#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}

}
}
/*This is a function problem.You only need to complete the function given below*/
/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/
vector<vector<int>> v;
int mem[101][101];
int solve(int d1, int d2) {
	int& rt = mem[d1][d2];
	if (~rt)return rt;
	rt = 0;
	for (int i = 0; i < (int)(v.size()); i++) for (int j = 0; j < 3; j++) {
		int nxt1 = (j + 1) % 3, nxt2 = (j + 2) % 3;
		if (v[i][nxt1] > d1 && v[i][nxt2] > d2) {
			rt = max(rt, v[i][j] + solve(v[i][nxt1], v[i][nxt2]));
		}
		swap(nxt1, nxt2);
		if (v[i][nxt1] > d1 && v[i][nxt2] > d2) {
			rt = max(rt, v[i][j] + solve(v[i][nxt1], v[i][nxt2]));
		}
	}
	return rt;
}

int maxHeight(int height[], int width[], int length[], int n)
{
	v = vector<vector<int>>(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		v[i] = { height[i],width[i],length[i] };
	memset(mem, -1, sizeof(mem));
	return solve(0, 0);
}
