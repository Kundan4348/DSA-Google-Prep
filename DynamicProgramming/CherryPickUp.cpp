/*
    If we are saying that go from one position to another and then come back to the same position.
    Then we can send two person from the same position and reach to the destination.
*/


class Solution {
     int memo[51][51][51][51];
    int maxCherryPick(int r1,int c1,int r2,int c2, vector<vector<int>>& grid){
        if(r1>=grid.size() || c1 >= grid[0].size() || r2 >= grid.size() || c2>=grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1)return INT_MIN;

        if(r1 == grid.size()-1 && c1 == grid[0].size()-1)return grid[r1][c1];
        if(r2 == grid.size()-1 && c2 == grid[0].size()-1)return grid[r2][c2];
        if(memo[r1][c1][r2][c2] != -1)return memo[r1][c1][r2][c2];
        int cherries = 0;
        cherries =  max(maxCherryPick(r1+1,c1,r2+1,c2,grid),
                    max(maxCherryPick(r1+1,c1,r2,c2+1,grid),
                    max(maxCherryPick(r1,c1+1,r2+1,c2,grid),
                        maxCherryPick(r1,c1+1,r2,c2+1,grid))));

        if(r1 == r2 && c1 == c2)cherries+= grid[r1][c1];
        else cherries+= grid[r1][c1] + grid[r2][c2];
        
        return memo[r1][c1][r2][c2] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
        return max(0,maxCherryPick(0,0,0,0,grid));
    }
};