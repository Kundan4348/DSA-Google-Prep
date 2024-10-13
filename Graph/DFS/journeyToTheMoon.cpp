 /*

https://www.hackerrank.com/challenges/journey-to-the-moon/problem

    the people in 1 component cant go together but thet can go with rest of the people
*/

 int dfs(int node,vector<vector<int>>& adjList,vector<int>& visited){
     
     int count = 0;
     for(int i=0;i<adjList[node].size();++i){
         int newNode = adjList[node][i];
         if(visited[newNode] == 0){
             visited[newNode] = 1;
             count+=dfs(newNode,adjList,visited);
         }
     }
     return count + 1;
 }

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> adjList(n);
    for(int i=0;i<astronaut.size();++i){
        int a = astronaut[i][0];
        int b = astronaut[i][1];
        
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    vector<int> visited(n,0);
    long long prevCount = 0;
    long long totalSum = 0;
    for(int i=0;i<n;++i){
        if(visited[i] == 0){
            visited[i] = 1;
            long long count = dfs(i,adjList,visited);
            // cout<<i<<" "<<count<<endl;
            totalSum+= (prevCount*count);
            prevCount+=count;
        }
    }
    
    return totalSum;
}