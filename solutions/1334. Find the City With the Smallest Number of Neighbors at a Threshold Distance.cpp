class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e5));
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u][v] = wt;
            adj[v][u]= wt;
        }
        
        for(int k = 0;k< n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                   adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        vector<int> count(n,0);
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(adj[i][j] <= threshold && i!=j) count[i]++;
            }
        }
        int ans = 0;
        for(int i = 1;i<n;i++){
            cout<<count[i]<<" "<<count[ans]<<endl;
            if(count[i] <= count[ans])
                 ans = i;
        }
        
        return ans;
    }
};
