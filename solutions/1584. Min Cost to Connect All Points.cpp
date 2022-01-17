class Solution {
public:
    #define pair pair<int,int>
    int distance(vector<int> a, vector<int> b){
        
        int dis = abs(a[0]-b[0]) + abs(a[1]-b[1]);
        return dis;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
       
        int n = points.size();
        vector<pair> adj[n];
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    adj[i].push_back({j,wt});
                }
            }
        }
        
       priority_queue<pair,vector<pair>,greater<pair>> q;
       int visited[1000]={0};
       long long int ans =0;
        q.push({0,0});
        while(q.empty()==false){
            
            auto temp = q.top(); q.pop();
            int wt = temp.first;
            int src = temp.second;
​
