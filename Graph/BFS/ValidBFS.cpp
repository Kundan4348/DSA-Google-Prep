 
#include <bits/stdc++.h> 
using namespace std;
#define ll long long


int main() { 
	int n=6;
	vector<vector<int>> adjList;
	vector<int> visited(n,0);
	vector<int> res;
	int start = 0;
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while(!q.empty()){
		int currNode = q.top();
		res.push(currNode);
		
		q.pop();

		for(int i=0;i<adjList[currNode].size();++i){
			int newNode = adjList[currNode][i];
			if(visited[newNode] == 0){
				visited[currNode] = 1;
				q.push(newNode);
			}
		}
	}

} 