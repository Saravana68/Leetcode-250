class Solution {
public:
    int dx[8] = {-1,1,0,0,-1,1,-1,1};
    int dy[8] = {0,0,1,-1,-1,1,1,-1};
    
    bool isValid(int &i,int &j, vector<vector<int>> &grid,vector<vector<int>> &vis){
        if(i >=0 && j>=0 && i<grid.size() && j<grid.size() && !vis[i][j] && !grid[i][j]) return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
        
        int n = grid.size();
        
        if(grid[0][0] == 1) return -1;
        if(grid[n-1][n-1] == 1) return -1;
        
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        
        while(q.size()){
            
            int count = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            vis[i][j] = 1;
            if(i == n-1 && j == n-1) return count;
            
            for(int k = 0;k<8;k++){
                int newx = i + dx[k];
                int newy = j + dy[k];
                if(!isValid(newx,newy,grid,vis)) continue;
                vis[newx][newy] = 1;
                q.push({count+1,{newx,newy}});
            }
        }
        
