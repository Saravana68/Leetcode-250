class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
     queue<int> q;
     vector indegree(n,0);
​
    //creating adjacency list
    vector<vector<int>>adj(n);
    for(auto &x:pre)adj[x[1]].push_back(x[0]);
    
    //storing indegree of each vertex
    for(int i=0;i<n;i++){
        for(int it:adj[i])indegree[it]++;
    }
    
    //pushing the vertices with indegree=0 in the queue
    for(int i=0;i<n;i++){
        if(indegree[i]==0)q.push(i);
    }
    
    //start of bfs
    vector<int>ans;
    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        count++;
        
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    //if count != (number of vertices in the graph) there is a cycle in the graph and toposort cannot take place, else we produce the toposort
    if(count!=n)return {};
    return ans;
} 
    
};
