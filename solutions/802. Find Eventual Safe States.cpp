class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> adj[N];
        vector<int> indegree(N);
        for(int u = 0;u<graph.size();u++){
            for(int v : graph[u]){
                adj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes = {};
        
        for(int i =0;i<N;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(q.size()){
            int u = q.front(); 
            q.pop();
            safeNodes.push_back(u);
            for(int v : adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
