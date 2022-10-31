class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src] =0;
        q.push({0,{src,0}});
        
        while(q.size()){
            auto it = q.front(); q.pop();
            int count = it.first;
            int u = it.second.first;
            int wt = it.second.second;
            
            if(count> k) continue;
            for(auto it : adj[u]){
                int v = it.first;
                int edgeweight = it.second;
                if(dist[v] > wt + edgeweight && count<=k){
                   dist[v] = edgeweight + wt;
                    q.push({count +1,{v,dist[v]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
