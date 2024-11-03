 /* 
	This can be only possible when the graph is DAG
	It sets the ordering of the graph
	We can also use DFS to solve this code

	Time Complexity = O(V+E)
 */



#include <bits/stdc++.h> 
using namespace std;
#define ll long long


int solve(int n,vector<vector<int>> edges, vector<vector<int>> adjList){
	vector<int> indegree(n,0);
	for(int i=0;i<edges.size();++i){
		indegree[edges[i][1]]++;
	}
	queue<int> q;
	for(int i=0;i<indegree.size();++i){
		if(indegree[i] == 0)q.push(i);
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		res.push_back(node);


		for(int i=0;i<adjList[node].size();++i){
			int adjNode = adjList[node][i];
			indegree[adjNode]--;
			if(indegree[adjNode] == 0){
				q.push(adjNode);
			}
		}
	}

	if(res.size()!=edges.size())cout<<”Cycle present”;
	return res;


}
 
int main() { 
	int t;
	cin>>t;
	for(int times=0;times<t;++times){
		
	}

	return 0; 
} 
