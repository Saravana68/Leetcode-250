class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        set<pair<int,pair<int,int>>> st;
        st.insert({grid[0][0],{0,0}});
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]= grid[0][0];
        
        while(st.size()){
            auto it = *(st.begin());
            st.erase(it);
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == m-1) return time;
            
            for(int i = 0;i<4;i++){
                int newr = row + dx[i];
                int newc = col + dy[i];
                
                if(newr <0 || newc <0 || newr >= n || newc >= m) continue;
                int newtime = max(time,grid[newr][newc]);
                if(newtime < dist[newr][newc]) {
                    if(dist[newr][newc] != INT_MAX) 
                        st.erase({dist[newr][newc],{newr,newc}});
                    dist[newr][newc] = newtime;
                    st.insert({dist[newr][newc],{newr,newc}});
                }
            }
        }
        return -1;
    }
