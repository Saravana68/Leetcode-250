class Solution {
public:
    
    void doDFS(int u,vector<vector<int>> &stones,vector<int> &vis){
        
        vis[u] = 1;
        for(int v =0; v < stones.size();v++){
         if(vis[v]) continue;
         if(stones[u][0] == stones[v][0] || stones[v][1] == stones[u][1])
             doDFS(v,stones,vis);
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        int count= 0;
        
        vector<int>vis(n,0);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                doDFS(i,stones,vis);
                count++;
            }
        }
        
        return n - count;
    }
};
