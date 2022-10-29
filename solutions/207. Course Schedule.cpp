class Solution {
public:
    
    bool  dfs(int u, vector<int> &vis, vector<int> &rec, vector<int> adj[]){
        vis[u] = 1;
        rec[u] = 1;
        for(int v : adj[u]){
            if(vis[v] == false){
                if(dfs(v,vis,rec,adj)) return true;
            }
            else if(rec[v] == 1) return true;
        }
        rec[u] = 0;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& arr) {
        vector<int> adj[N];
        for(vector<int> it : arr){
            adj[it[0]].push_back(it[1]);
        }
        for(auto it : adj){
            for(auto x: it)
                cout<<x<<" ";
            cout<<endl;
        }
        vector<int> vis(N,0);
        vector<int> rec(N,0);
        for(int i =0;i<N;i++){
            if(vis[i] == false){
                if(dfs(i,vis,rec,adj)) return false;
            }
        }
        return true;
    }
};
