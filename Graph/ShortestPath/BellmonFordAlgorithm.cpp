 
#include <bits/stdc++.h> 
using namespace std;
#define ll long long


vector<int> bellmonFordAlgorithm(int n,vector<vector<int>>& edges, int start){
	// edges is in the form of {u,v,w} -> u = source, v = destination, w = weight
	// we need to do the iteration a total of n-1 times(relaxation) and then the shortetPath array will give me the result
	// TO Detect Negative cycle: we will do one more time relaxation and if the value changes then we can say that
	// yes we have a negative edge cycle
		vector<int> shortedDist(n,INT_MAX);

		shortedDist[start] = 0;

		for(int i=0;i<n-1;++i){
			//iterate all the edges and relax everything
			for(auto &edge: edges){
				int u = edge[0];
				int v = edge[1];
				int wt = edge[2];
				if(shortedDist[u]!=INT_MAX){
					if(shortedDist[u] + wt < shortedDist[v]){
						shortedDist[v] = shortedDist[u] + wt;
					}
				}
			}
		}

		//If we want to check for cycle we will do one more iteration and if we find that shortedDist array
		//changes then we can say that we have detected a cycle (-ve edge cycle)
		for(auto &edge: edges){
				int u = edge[0];
				int v = edge[1];
				int wt = edge[2];
				if(shortedDist[u]!=INT_MAX){
					if(shortedDist[u] + wt < shortedDist[v]){
						shortedDist[v] = shortedDist[u] + wt;
						cout<< "There is an negative edge cycle";
						return {};
					}
				}
		}

		return shortedDist;

}
 
int main() { 
	vector<vector<int>> edges = {
		{0,1,-1},
		{0,2, 5},
		{1,3, 2},
		{2,4, -2}
	}
	vector<int> res = bellmonFordAlgorithm(4,edges,0);
	return 0; 
} 