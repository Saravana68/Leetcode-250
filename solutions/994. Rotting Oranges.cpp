        return false;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid){
        
        
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh_oranges = 0;
        // collecting rotten oranges in minute 0
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j] == 2){ 
                    cout<<i<<j<<endl;
                    q.push({i,j});
                }if(grid[i][j] == 1) fresh_oranges++;
            }
        }
        
        if(fresh_oranges == 0) return 0;
        int count  = 0;
        while(!q.empty()){
            int len = q.size();
            while(len){
                auto it = q.front(); q.pop();
                for(int k = 0;k<4;k++){
                  int x = it.first + dx[k];
                  int y = it.second + dy[k];
                  if(isValid(x,y,grid)){
                      grid[x][y] = 2;
                      q.push({x,y});
                  }
                }
                len--;
            }
            count++;
        } 
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count-1;
    }
};
