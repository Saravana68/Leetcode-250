class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board,vector<vector<bool>> &vis,bool &flag){
        
        if( i < 0 || j <0 || i >= board.size() || j>=board[0].size() || board[i][j] == 'X'|| vis[i][j])
            return ;
        
        vis[i][j] = true;
        if(i ==0 || j ==0 || i >= board.size()-1 || j >= board[0].size()-1) 
            flag = true;
            
        
        dfs(i+1,j,board,vis,flag);
        dfs(i-1,j,board,vis,flag);
        dfs(i,j+1,board,vis,flag);
        dfs(i,j-1,board,vis,flag);
    }
    void mark(int i,int j,vector<vector<char>> &board){
        if(i <0 || j <0 || i>= board.size() || j>=board[0].size() || board[i][j] =='X')
            return;
        
        board[i][j] = 'X';
        
        mark(i+1,j,board);
        mark(i-1,j,board);
        mark(i,j+1,board);
        mark(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 1;i<board.size()-1;i++){
            for(int j = 1;j<board[0].size()-1;j++){
                 if(!vis[i][j] && board[i][j] == 'O'){
                     bool flag = false;
                     dfs(i,j,board,vis,flag);
                     if(!flag)
                         mark(i,j,board);
                 }
            }
        }
    }
};
