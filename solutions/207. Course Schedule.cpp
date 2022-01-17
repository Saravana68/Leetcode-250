class Solution {
public:
    bool dfs(int src,vector<int> adj[],vector<int> &recSt,vector<int> &visited){
        
        visited[src] =1;
        recSt[src] = 1;
        
        for(auto v : adj[src]){
            if(visited[v] == false){
                if(!dfs(v,adj,recSt,visited))
                    return false;
            }
            else if(recSt[v])
                return false;
                
        }
        recSt[src] = 0;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& grid) {
        
        vector<int> adj[n];
        for(int i =0;i<grid.size();i++){
           
            int u = grid[i][1];
            int v = grid[i][0];
            adj[u].push_back(v);
        }
        
    /* start dfs to check cycle exist in directed graph or not */
    /* approach is if vertex forms backedge with any of its parent present in 
        stack then cycle exist return false */
         
        vector<int> visited(n,0);
        vector<int> recSt(n,0);
