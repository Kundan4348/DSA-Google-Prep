/*
    Do a multisource BFS to find the manhattan distance.
    Use binary search to find and value and iterate over the grid using bfs
    or 
    Use priority queue to and keep maximum at top and find the minimum in the adjacent and push in the queue.

    https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=company&envId=google&favoriteSlug=google-thirty-days&role=full-stack
*/



class Solution {
    //Will give TLE
    //Memoization will also not work here
    // int dfs(int i,int j,vector<vector<int>>& grid){
    //     if(i<0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] ==-1)return INT_MIN;
    //     if(i == grid.size()-1 && j == grid[0].size()-1)return grid[i][j];

    //     int val = grid[i][j];
    //     grid[i][j] = -1;
    //     int maxi = max(0,dfs(i+1,j,grid));
    //     maxi = max(maxi,dfs(i-1,j,grid));
    //     maxi = max(maxi,dfs(i,j+1,grid));
    //     maxi = max(maxi,dfs(i,j-1,grid));
    //     grid[i][j] = val;
    //     return min(val,maxi);
    // }


public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    q.push({i,j});
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0;k<dirs.size();++k){
                int newI = i + dirs[k][0];
                int newJ = j + dirs[k][1];
                if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size() || grid[newI][newJ] !=-1)continue;
                int newDist = grid[i][j] + 1;
                q.push({newI,newJ});
                grid[newI][newJ] = newDist;
            } 
        }
        

        // return dfs(0,0,grid);
        //BFS
        priority_queue<vector<int>> pq;
        pq.push({grid[0][0],0,0});
        grid[0][0] = -1;

        while(!pq.empty()){
            int cost = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            
            pq.pop();

            if(i == grid.size()-1 && j == grid[0].size()-1)return cost;

            for(int k = 0;k<dirs.size();++k){
                int newI = i + dirs[k][0];
                int newJ = j + dirs[k][1];
                if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size() || grid[newI][newJ] ==-1)continue;
                pq.push({min(cost,grid[newI][newJ]),newI,newJ});
                grid[newI][newJ] = -1;
            } 

        }

        return 0;


    }
};