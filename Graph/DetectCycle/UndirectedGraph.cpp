 
#include <bits/stdc++.h> 
using namespace std;
#define ll long long


int solve(int node,vector<vector<int>>& graph,vector<int>& visited,int parent){
	if(visited[node] == 2)return true;
	if(visited[node] == 1)return false;

	visited[node] = 1;

	for(int i=0;i<graph[node].size();++i){
		int newNode = graph[node][i];
		if(newNode!=parent){
			if(!solve(newNode,graph,visited,node))return false;
		}
	}

	visited[node] = 2;
	return true;

}
 
int main() { 
	vector<int> visited;
	vector<vector<int>> graph;

	for(int i=0;i<n;++i){
		if(visited[i] == 0){
			if(!solve(i,graph,visited,-1))return false;
		}
	}

	return true; 
} 