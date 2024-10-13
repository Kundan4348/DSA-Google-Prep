/* A graph is bipartite when the cycle inside of it is even or there is no cycle
   ->We can easily solve the problem of IsBipartite graph by DFS/BFS alternate colouring
   -> If there is odd cycle then it is not Bipartite
   -> We can check using even and odd cycle by two colors (0,1)
*/



class Solution {
    bool bfs(int num,vector<vector<int>>& graph,vector<int>& coloured){
        queue<int> q;

        q.push(num);
        coloured[num] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int color = coloured[node];
            int newColor = color^1;

            for(int i=0;i<graph[node].size();++i){
                int newNode = graph[node][i];
                if(coloured[newNode] == color)return false;
                if(coloured[newNode] == -1){
                    coloured[newNode] = newColor;
                    q.push(newNode);
                }
            }

        }   

        return true;
    }    
public:
    bool isBipartite(vector<vector<int>>& graph) {
           vector<int> coloured(graph.size(),-1);

           for(int i=0;i<graph.size();++i){
                if(coloured[i]==-1){
                    if(!bfs(i,graph,coloured))return false;
                }
           }
           return true;
    }
};