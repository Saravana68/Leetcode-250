class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,int i,int j,int n,int m,vector<vector<bool>> &vis,int &sum){
        
        if(i<0 || j< 0|| i>=n || j>=m || vis[i][j] || grid[i][j] !=1)
            return ;
       
        sum++;
        vis[i][j] = true;
        dfs(grid,i+1,j,n,m,vis,sum);
        dfs(grid,i,j+1,n,m,vis,sum);
        dfs(grid,i-1,j,n,m,vis,sum);
        dfs(grid,i,j-1,n,m,vis,sum);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                
                if(grid[i][j] && vis[i][j] == false){
                     sum =0;
                    dfs(grid,i,j,n,m,vis,sum);
                    res = max(res,sum);
                }
               
            }
        }
        return res;
        
        
    }
};
