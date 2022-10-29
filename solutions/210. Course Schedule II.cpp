class Solution {
public:
    bool dfs(int u,vector<int> &vis,vector<int> &rec,vector<int> adj[],stack<int> &st){
        vis[u] =1 ;
        rec[u]= 1;
        for(int v : adj[u]){
            if(!vis[v]){
                if(dfs(v,vis,rec,adj,st)) return true;
            }
            else if(rec[v] == 1) return true;
        }
        rec[u] =0;
        st.push(u);
        return false;
        
    }
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        stack<int> st;
        vector<int> adj[N];
        vector<int> res;
        vector<int> rec(N,0);
        for(vector<int> it : arr){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(N,0);
        for(int i =0;i<N;i++){
            if(!vis[i]){
                if(dfs(i,vis,rec,adj,st)) return {};
            }
        }
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
