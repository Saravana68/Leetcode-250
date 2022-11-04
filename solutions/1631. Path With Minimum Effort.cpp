class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0;
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        
        while(st.size()){
            auto it = *(st.begin());
            st.erase(it);
            
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return effort;
                
            for(int k = 0;k<4;k++){
                int newr = row + dx[k];
                int newc = col + dy[k];
                
                if(newr <0 || newr >= n || newc <0 || newc >= m) continue;
                int neweffort = max(effort,abs(arr[newr][newc] - arr[row][col]));
                if(neweffort < dis[newr][newc]){
                    if(dis[newr][newc] != INT_MAX)
                        st.erase({dis[newr][newc],{newr,newc}});
                    
                    dis[newr][newc] = neweffort;
                    st.insert({dis[newr][newc],{newr,newc}});
                    
                }
            }
        }
        return -1;
