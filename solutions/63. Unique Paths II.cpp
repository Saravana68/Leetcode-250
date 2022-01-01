       03. convert recursion into tabulation dp solution
       04. Now do modification on DP solution 
    */
    
    /*  MODIFIED DP SOLUION :
        --------------------
        01. if grid[i][j] has obstacle then we entire path through that cell is invalid
        02. first traverse row wise and then col wise
        03. check if obstacel present or not i.e grid[i][j] ==1 
        04. if present mark that cell + entire row/ entire col as 0;
    */
    
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
       int n = grid.size();
       int m = grid[0].size();
       if(grid[0][0])
           return 0;
       int dp[n][m];
       bool flag = false;
        
       dp[0][0] = 1;
        
       for(int i =1;i<n;i++){
           if(flag || grid[i][0] == 1){
              flag = true;
              dp[i][0] = 0;
           }
           else
               dp[i][0] = 1;
       }
        flag = false;
        for(int i =1;i<m;i++){
           if(flag || grid[0][i] == 1){
              flag = true;
