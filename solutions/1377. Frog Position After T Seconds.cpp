class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        if(edges.size() <=1)
             return 1.0;
        
        
        vector<vector<int>> adj(n+1);
        vector<int> prob(n+1,-1);
        
        // Adjacency list 
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        prob[1] = 0;
        int level = 0;
        queue<int> q;
