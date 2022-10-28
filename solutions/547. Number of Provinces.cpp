class Solution {
public:
    
    void doDfs(int u,vector<vector<int>> &adj, vector<int> &vis){
        vis[u] = 1;
        for(int v = 0;v < adj[u].size();v++){
            if(adj[u][v] && !vis[v])
                doDfs(v,adj,vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,false);
        int count = 0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                count++;
                doDfs(i,adj,vis);
            }
        }
        return count;
    }
};
