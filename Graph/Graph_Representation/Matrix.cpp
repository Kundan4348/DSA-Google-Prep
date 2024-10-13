 
#include <bits/stdc++.h> 
using namespace std;
#define ll long long

int main() { 
	int n=6;
	vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

	int matrix[n][n];
	memset(matrix,0,sizeof(n));

	for(int i=0;i<edges.size();++i){
		int a = edges[i][0];
		int b = edges[i][1];
		matrix[a][b] = 1;
	}

	for(int i=0;i<n;++i){
		cout<<i; //source
		for(int j=0;j<n;++j){
			if(matrix[i][j] == 1){
				cout<<j; //target
			}
		}
		cout<<endl;
	}
} 