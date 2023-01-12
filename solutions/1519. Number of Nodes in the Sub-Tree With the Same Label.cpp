class Solution {
public:
    vector<int> dfs(int u,vector<int> adj[],vector<int> &vis,vector<int> &res,string &pattern){
        if(vis[u])
            return vector<int>(26,0);
        vis[u] = 1;
        vector<int> current(26,0);
        int uIdx = pattern[u]-'a';
        current[uIdx] = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                vector<int> child = dfs(v,adj,vis,res,pattern);
                for(int i = 0;i<26;i++)
                     current[i] += child[i];
                
            }
        }
        res[u] = current[uIdx];
        return current;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string pattern) {
        vector<int> vis(n,false);
        vector<int> res(n,0);
        vector<int> adj[n];
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,adj,vis,res,pattern);
        return res;
    }
};
