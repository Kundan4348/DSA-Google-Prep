// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/


class UnionFind {
    vector<int> parent;
    vector<int> rank;
    int components;
    public:

    UnionFind(int n){
        components = n;
        for(int i=0;i<n;++i){
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }

    bool _union(int a,int b){
        int x = find(a);
        int y = find(b);

        if(x == y)return false;
        if(rank[x] > rank[y]){
            parent[y] = x;
            rank[x]+=rank[y];
        } else {
            parent[x] = parent[y];
            rank[y]+=rank[x];
        }

        components--;
        return true;
    }

    bool isComplete(){
        if(components == 1)return true;
        return false;
    }
};


    int getMst(int n,vector<vector<int>>& edges,int blockedEdge, int preEdge=-1){
        UnionFind uf(n);
        int weight = 0;

        if(preEdge != -1){
            weight+=edges[preEdge][2];
            uf._union(edges[preEdge][0],edges[preEdge][1]);
        }

        for(int i=0;i<edges.size();++i){
            if(i == blockedEdge)continue;
            vector<int> edge = edges[i];
            if(uf._union(edge[0],edge[1])){
                weight+=edge[2];
            }
        }

        
        if(uf.isComplete())return weight;

        return INT_MAX;
    }




class Solution {

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();++i){
            edges[i].push_back(i);
        }

        sort(edges.begin(),edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });

        int originalMstCost = getMst(n,edges,-1);
        vector<int> critical,pseudoCritical;
        for(int i=0;i<edges.size();++i){
            if(getMst(n,edges,i) > originalMstCost){
                critical.push_back(edges[i][3]);
            } else if(getMst(n,edges,-1,i) == originalMstCost){
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        return {critical, pseudoCritical};
    }
};