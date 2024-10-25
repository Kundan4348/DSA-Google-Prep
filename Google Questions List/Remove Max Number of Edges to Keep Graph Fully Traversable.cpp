class UnionFind{
    vector<int> parent;
    vector<int> rank;
    int components;
    public:
    

    UnionFind(int n){
        components = n;
        for(int i=0;i<=n;++i){
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findParent(int child){
        if(parent[child] == child)return child;

        return parent[child] = findParent(parent[child]);
    }

    int unionParent(int child1, int child2){
        int p1 = findParent(child1);
        int p2 = findParent(child2);

        if(p1 == p2)return 0;
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1]+=rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2]+=rank[p1];
        }
        components--;
        return 1;
    }

     bool isConnected() {
        return components == 1;
    }
};



class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //creating two objects
        UnionFind Bob(n), Alice(n);
        int totalRequiredEdges = 0;
        for(int i=0;i<edges.size();++i){
            if(edges[i][0] == 3){
                int possibleEdge = Bob.unionParent(edges[i][1],edges[i][2]);
                possibleEdge|= Alice.unionParent(edges[i][1],edges[i][2]);
                totalRequiredEdges+=possibleEdge;
            }
        }
        

        for(int i=0;i<edges.size();++i){
            if(edges[i][0] == 1){
                int possibleEdge = Alice.unionParent(edges[i][1],edges[i][2]);
                totalRequiredEdges+=possibleEdge;
            } else if(edges[i][0] == 2){
                 int possibleEdge = Bob.unionParent(edges[i][1],edges[i][2]);
                 totalRequiredEdges+=possibleEdge;
            }
        }


        if(Bob.isConnected() == 1 && Alice.isConnected() == 1){
            int totalEdges = edges.size();
            return totalEdges - totalRequiredEdges;
        }
        return -1;
        
    }
};