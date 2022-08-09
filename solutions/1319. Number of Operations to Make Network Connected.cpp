​
class Solution {
public:
    void DFS(unordered_map<int,vector<int>>&adj, int curr, vector<bool>&visited){
        visited[curr]=true;
        for(auto it: adj[curr]){
            if(visited[it]==false){
                DFS(adj,it,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        int edges = connections.size();
        if(edges<n-1){
            return -1;
        }
        for(int i=0; i<connections.size();++i){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int components = 0;
        for (int i=0; i<n; i++){
            if(visited[i]==false){
                components++;
                DFS(adj,i,visited);
            }
        }
        return components-1;
    }
};
