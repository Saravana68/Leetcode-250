class Solution {
public:
    // Recursion TLE
    int solve(int i, int j, vector<vector<int>> &grid){
        if(i == grid.size() -1){
            return grid[i][j];
        }
        int down = grid[i][j] + solve(i+1,j,grid);
        int diagonal = grid[i][j] + solve(i+1,j+1,grid);
        
        return min(down,diagonal);
    }
    
    // Recursion + Memoization
    int solve1(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i == grid.size() -1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = grid[i][j] + solve1(i+1,j,grid,dp);
        int diagonal = grid[i][j] + solve1(i+1,j+1,grid,dp);
        
        return dp[i][j] = min(down,diagonal);
    }    
    // Tabulation
    int solve2(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
        int m = grid.size();
        
        dp[m-1] = grid[m-1];
        
        for(int i = m-2; i>=0; i--){
            for(int j = 0;j < grid[i].size();j++){
                
                int down = grid[i][j] + dp[i+1][j];
                int diagonal = grid[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
