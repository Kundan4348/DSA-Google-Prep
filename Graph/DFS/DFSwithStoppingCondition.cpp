//https://leetcode.com/problems/maximum-path-quality-of-a-graph/

/*
    In this problem we get to know a differet variety of DFS with a stopping condition 
    of time rather than all visited.
*/

class Solution {
void dfs(int node,vector<vector<pair<int,int>>>& adjList,unordered_map<int,int>& visited,int &maxTime,vector<int>& values,int &res,int currSum,int time){
	if(time > maxTime)return;
	visited[node]++;
	if(visited.count(node)>0){
        if(node == 0){
            res = max(res,currSum);
        }
    }
	
    for(int i=0;i<adjList[node].size();++i){
        int newNode = adjList[node][i].first;
        int travelCost = adjList[node][i].second;
        if(visited[newNode] == 0){
            dfs(newNode,adjList,visited,maxTime,values,res,currSum + values[newNode],time+travelCost);
        }else{
            dfs(newNode,adjList,visited,maxTime,values,res,currSum,time+travelCost);
        }
            
    }
    visited[node]--;
}

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
       int n = values.size();
        vector<vector<pair<int,int>>> adjList(n);
	  
        for(int i=0;i<edges.size();++i){
            int a = edges[i][0];
            int b = edges[i][1];
            int cost = edges[i][2];
            adjList[a].push_back({b,cost});
            adjList[b].push_back({a,cost});
        }
        
        unordered_map<int,int> visited;
        int res = 0;
        dfs(0,adjList,visited,maxTime,values,res,values[0],0);
        return res;
    }
};