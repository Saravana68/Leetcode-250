class Solution {
public: 
    bool seen;
    
    void dfs(vector<vector<char>> & board,vector<vector<bool>>&vis,int i,int j,int r,int c)
    {
       if(i<0 || i>=r || j<0 || j>=c || board[i][j] == 'X' || vis[i][j])
           return ;
        
        vis[i][j] = true;
        
        if(i<=0 || j<=0 || i>=r-1 || j>=c-1)
            seen = true;
        
        dfs(board,vis,i-1,j,r,c);
        dfs(board,vis,i+1,j,r,c);
        dfs(board,vis,i,j-1,r,c);
        dfs(board,vis,i,j+1,r,c);
    }
    void mark(vector<vector<char>> & board,int i,int j,int r,int c){
        
        if(i<0 || j<0 || i>=r || j >=c || board[i][j] == 'X')
             return ;
      
        
        board[i][j] = 'X';
        
         
        mark(board,i-1,j,r,c);
        mark(board,i+1,j,r,c);
        mark(board,i,j-1,r,c);
        mark(board,i,j+1,r,c);
    }
    void solve(vector<vector<char>>& board) {
        
        int r = board.size();
        if(r<=1) return ;
        int c = board[0].size();
        if(c<=1) return ;
        
        vector<vector<bool>> vis (r,vector<bool>(c,false));
        
        for(int i =1;i<r-1;i++){
            for(int j =1 ;j<c-1;j++){
                
                if(board[i][j] == 'O' && !vis[i][j]) {
                    seen = false;
                    dfs(board,vis,i,j,r,c);
                    if(seen == false)
                        mark(board,i,j,r,c);
                    seen = true;
                }
            }
        }
        
        
    }
};
