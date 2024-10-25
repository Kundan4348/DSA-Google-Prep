 /*
	Keep the starting node in the priority queue as {wight,node,parentNode}
	if the node is not visited and has parent then add it to the spanTree as result
	Iterate to its neighbours and then if the neighbours are not visited then add it to the queue
	REMEMBER: Do not mark the neighbour nodes in the visited array.
 */



#include <bits/stdc++.h> 
using namespace std;
#define ll long long


int solve(int n, vector<vector<pair<int,int>>>& adjList){

	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
	vector<int> visited(n,0);
	vector<vector<int>> minimumSpanTree;
	int minimumCost = 0;
		//weight//node//parentNode
	pq.push({0,0,-1});
	while(!pq.empty()){
		int wt = pq.top()[0];
		int node = pq.top()[1];
		int parentNode = pq.top()[2];
		pq.pop();

		if(visited[node] == 1)continue;

		if(parentNode!=-1){
			minimumSpanTree.push_back({node,parentNode});
			minimumCost+=wt;
		}
		visited[node] = 1;

		for(auto child: adjList[node]){
			int newNode = child.first;
			int newWt = child.second;
			if(visited[newNode] == 0){
				pq.push({newWt,newNode,node});
			}
		}
	}

	return minimumCost;

}
 
int main() { 
	int t;
	cin>>t;
	for(int times=0;times<t;++times){
	
	}

	return 0; 
} 