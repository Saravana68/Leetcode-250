class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
    if(board[0][0] != -1) return -1;
    int Y = board.size(), X = board[0].size();
    
    int id = 1, lim = Y*X;
    vector<int>g(++lim,0);
    vector<int>vis(lim,0);
    
    for(int y = Y-1, flag = 0; y >= 0; y--, flag ^= 1)
      if(flag) 
        {for(int x=X-1; x >= 0; x--, id++) if(board[y][x] != -1) g[id] = board[y][x];}
      else 
        {for(int x = 0; x != X; x++, id++) if(board[y][x] != -1) g[id] = board[y][x];}
       
    queue<int>q;
    q.push(1);
    int level = 0, end = lim - 1;
    
    while(!q.empty()){
      level++;
      int n = q.size(); 
      while(n--){
        int t = q.front(); q.pop();
        if(vis[t]) continue;
        vis[t] = 1;  
          
        for(int i = min(lim, ++t + 6); t != i; t++){
          g[t] ? q.push(g[t]) : q.push(t);          
          if(q.back() == end) return level;
        }
      }
    }
    
    return level;
  }
};
