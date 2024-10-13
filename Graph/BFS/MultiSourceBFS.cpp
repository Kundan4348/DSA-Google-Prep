/* 
    This is a really good usecase of multi-source BFS 
    In this question we see how we can traverse from a point to that point itself
    using minimum path.
    We can go back and forth btw nodes but should never land on the same config again
    
*/

//847. Shortest Path Visiting All Nodes



class touple{
    public:
        int node;
        int cost;
        int mask;

        touple(int node,int cost,int mask){
            this->node = node;
            this->cost = cost;
            this->mask = mask;
        }
};



class Solution {

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<touple> q;
        for(int i=0;i<n;++i){
            int newMask = (1<<i);
            touple newTouple(i,0,newMask);
            q.push(newTouple);
        }
        int allMask = (1<<n)-1;
        set<pair<int,int>> visited;

        while(!q.empty()){
            touple currTouple = q.front();
            q.pop();

            if(allMask == currTouple.mask){
                return currTouple.cost;
            }

            for(int i=0;i<graph[currTouple.node].size();++i){
                int newNode = graph[currTouple.node][i];
                int newMask = currTouple.mask | (1<<newNode);
                if(visited.find({newNode,newMask}) == visited.end()){
                    visited.insert({newNode, newMask});
                    touple newTouple(newNode,currTouple.cost + 1,newMask);
                    q.push(newTouple);
                }
            }

        }

        return -1;      
    }
};