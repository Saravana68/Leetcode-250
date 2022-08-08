class Solution {
public:
    
    int dp[201][201];
    
    
    bool isValid(int x ,int y , vector<vector<int>> &mat,vector<vector<int>> &vis,int val){
        if(x>= mat.size() || x <0 || y>=mat[0].size() || y<0 || vis[x][y] ==1 || val >=mat[x][y])
            return false;
        return true;
    }
    int row[4] ={1,-1,0,0};
    int col[4] = {0,0,-1,1};
    
    int dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &mat){
        
        if(dp[x][y] != -1) return dp[x][y];
        int temp = 0;
        for(int i =0;i<4;i++){
            int dx = x + row[i];
            int dy = y + col[i];
            if(isValid(dx,dy,mat,vis,mat[x][y]) == false)
                continue;
            vis[dx][dy] = 1;
            temp = max(temp,1+dfs(dx,dy,vis,mat));
            vis[dx][dy] = 0;
        }
        return dp[x][y] = temp;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0 ;
        
        vector<vector<int>> vis(r,vector<int>(c,0));
        
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                vis[i][j] = 1;
                ans = max(ans,1+dfs(i,j,vis,matrix));
                vis[i][j] =0;
            }
        }
