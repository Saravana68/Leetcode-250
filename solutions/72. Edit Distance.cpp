​
class Solution {
    
public:
    // Recursion + memoization
    int f(int i, int j, string &s1, string &s2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return f(i-1,j-1,s1,s2,dp);
        else{
            int deletion = f(i-1,j,s1,s2,dp);
            int replace = f(i-1,j-1,s1,s2,dp);
            int insert = f(i,j-1,s1,s2,dp);
            return dp[i][j] = 1 + min({deletion,replace,insert});
        }
    }
    
    // Tabulation + space optimization 
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        if(n == 0 ) return m;
        if(m == 0) return n;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0),cur(m+1,0);
        
        for(int i = 0;i<=m;i++)
            prev[i] = i;
        
        for(int i =1;i<=n;i++){
            cur[0] = i;
            for(int j = 1;j<=m;j++){
                
                 if(s1[i-1] == s2[j-1])
                       cur[j] = prev[j-1];
                else{
                    cur[j] = 1 + min({prev[j],cur[j-1],prev[j-1]});
                }
            }
            prev = cur;
        }
        
        return prev[m];
    }
};
