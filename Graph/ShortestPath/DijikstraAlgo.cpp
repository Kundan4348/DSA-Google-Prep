/*
	It finds the shortest path from source node to every other node
	It cannot have negative edge weight
	It cannot have negative edge cycle
	For negative weight cycle we can use Bellmanford Algo which will only detect negative cycle 
	but still willl not be able to solve the path for negative edge cycle
*/ 


#include <bits/stdc++.h> 
using namespace std;
#define ll long long


vector<int> solve(int n,vector<vector<pair<int,int>>>& adjList,int source){
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	vector<int> shortestPath(n,INT_MAX);
	shortestPath[source] = 0;
	pq.push({0,source});

	while(!pq.empty()){
		int node = pq.top()[1];
		int dist = pq.top()[0];
		pq.pop();

		for(int i=0;i<adjList[node].size();++i){
			int edgeWeight = adjList[node][i].second;
			int adjNode = adjList[node][i].first;
			if(dist + edgeWeight < shortestPath[adjNode]){
				pq.push({dist + edgeWeight, adjNode});
				shortestPath[adjNode] = dist + edgeWeight;
			}
		}
	}
	return shortestPath;

}
 
int main() { 
	int t;
	cin>>t;
	for(int times=0;times<t;++times){
	
	}

	return 0; 
} 