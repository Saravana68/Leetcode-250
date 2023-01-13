class Solution {
public:
    int answer = 1;
    int solve(int u, vector<int> adj[],string &str){
        if(adj[u].size() == 0) return 1;
        int first = 0;
        int second = 0;
        for(int v  : adj[u]){
            int temp = solve(v,adj,str);
            if(str[v] == str[u]) continue;
            if(temp > first ){
                second = first;
                first = temp;
            }
            else second = max(second,temp);
        }
        answer = max(answer,first + second + 1);
        return max(first,second) + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        
        // Directed Graph formation
        int n = parent.size();
        vector<int> adj[n];
        for(int i = 1;i<n;i++)
            adj[parent[i]].push_back(i);
​
        solve(0,adj,s);
        return answer;
    }
};
