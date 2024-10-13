#include <bits/stdc++.h> 
using namespace std;
#define ll long long

 
int main() { 
	vector<vector<int>> edges = { {0,1}, {0,2},{1,2},{2,3}};
	int n = 3;

	vector<vector<int>> graph(n,vector<int>()); //one way to decalre
	unordered_map<int,vector<int>> graph; //another way to decalre

	for(int i=0;i<edges.size();++i){
		int source = edges[i][0];
		int target = edges[i][1];
		graph[source].push_back(target);
		graph[target].push_back(source);
	}

	for(int i=0;i<n;++i){
		cout<<i; //source
		for(int j=0;j<graph[i].size();++i){
			cout<<graph[i][j]<<" "; //target
		}
		cout<<endl;
	}
} 