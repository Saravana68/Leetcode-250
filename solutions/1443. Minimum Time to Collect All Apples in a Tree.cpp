class Solution {
public:
    pair<int,int> dfs(int u,vector<int> adj[],vector<bool> &hasApple,int parent){
        pair<int,int> temp = {0,hasApple[u]};
        for(int v : adj[u]){
            if(v!= parent){
                auto val = dfs(v,adj,hasApple,u);
                temp.first += (val.first + 2) * val.second;
                temp.second = temp.second || val.second;
            }
        }
        return temp;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i =0;i<(int)edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,adj,hasApple,0).first;
    }
};
