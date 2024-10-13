 
#include <bits/stdc++.h> 
using namespace std;
#define ll long long


int bfs(int start,int end,vector<vector<int>> &edges, vector<int> &visited){

	queue<pair<int,int>> q;
	q.push({start,0});
	visited[start] = 1;
	while(!q.empty()){
		int node = q.front().first;
		int len = q.front().second;
		q.pop();
		if(node == end)return len;

		for(int i=0;i<graph[node].size();++i){
			int newNode = graph[node][i];
			if(visited[newNode] == 0){
				visited[newNode] = 1;
				q.push({newNode,len+1});
			}
		}

	}

	return INT_MAX;
}


int solve(int n,vector<vector<int>> &edges){
	vector<vector<int>> adjList(n);
	for(int i=0;i<edges.size();++i){
		int a = edges[i][0];
		int b = edges[i][1];
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	int smallestCycle = INT_MAX;
	for(int i=0;i<edges.size();++i){
		int a = edges[i][0];
		int b = edges[i][1];
		vector<int> visited(n+1,0);
		smallestCycle = min(smallestCycle, bfs(a,b,adjList,visited));	
	}

	if(smallestCycle != INT_MAX)cout<<smallestCycle+1;
	return -1;

}
 
int main() { 
	int t;
	cin>>t;
	for(int times=0;times<t;++times){
	
	}

	return 0; 
} 