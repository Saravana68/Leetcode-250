class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        
 /* BruteForce:
   01. creating m*n auxillay array and store the output in that array
   02. then copy values from output array to board array
   03. but it breaks question requirement i.e O(1) solution
   04. Time: O(N3)  space: O(M*N)
 */
​
 /* optimal;
   01.approach is same for optimal solution also but we need to reduce space complexity
   02.after getting neighbour values for first row,if we update it in original array then while checking next rows 
   the neighbours will be yield different values
   03. we need to update cell at the same time when we check for next row cells ,this updation shouldn't change
   original neighbour values
   04.so store values as 2 and =-1
    2 -> dead cell converted to live after calculation
   -1 -> live cell converted to dead after calcualtion
   05. Time: O(N3) space: O(1)
   */
   
 
        
        
        
        int n = board.size(),m = board[0].size();
        //neighbour array
        int dx[8] = {0,1,0,-1,1,1,-1,-1};
        int dy[8] = {1,0,-1,0,1,-1,1,-1};
        
        //traverse the board
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int lc=0;   //live-count
                //travel all neighbours and see if they are 1
                for(int k=0;k<8;k++)
                    if(isSafe(i+dx[k],j+dy[k],n,m) && abs(board[i+dx[k]][j+dy[k]])==1)
                        lc++;
                    
                if(board[i][j]==0 && lc==3) board[i][j] = 2;    //live
                if(board[i][j]==1 && (lc<2 || lc>3))board[i][j] = -1;   //dead
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = board[i][j]>0? 1:0;
            }
        }
    }
    bool isSafe(int x,int y,int n,int m){
        return(x>=0 && y>=0 && x<n && y<m);
    }
};
