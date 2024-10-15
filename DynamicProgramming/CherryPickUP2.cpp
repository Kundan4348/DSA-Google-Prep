/*
    in this case a person can go in 3 direction that is {i+1,j-1}, {i+1,j}, {i+1,j+1}
    we see that both the robots will go to next row because they only have j changing but i is same for both of the robots 
    So we can keep only one i for both the robots

*/


class Solution {
    vector<int> dirs = {-1,0,1};
    int maxCherryPick(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& memo){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())return -1e8;
        if(i==grid.size()-1){
            if(j1 == j2)return grid[i][j1];
            return grid[i][j2] + grid[i][j1];
        }
        if(memo[i][j1][j2] != -1)return memo[i][j1][j2];

        int cherries = 0;
        for(int k:dirs){
            for(int j:dirs){
                cherries = max(cherries, maxCherryPick(i+1,j1+k,j2+j,grid,memo));
            }
        }
        if(j1 == j2)cherries+=grid[i][j1];
        else cherries+= grid[i][j1] + grid[i][j2];

        return memo[i][j1][j2]=cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> memo(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return max(0,maxCherryPick(0,0,grid[0].size()-1,grid,memo));
    }
};