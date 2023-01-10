class Solution {
public:
    bool isAllStars(string &s1,int idx){
        for(int i = 0;i<=idx;i++)
            if(s1[i] != '*') return false;
        return true;
    }
    bool solve(string &s1, string &s2,int i, int j,vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0) return isAllStars(s2,j);
        if(j < 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j] || s2[j] =='?')
            return dp[i][j] = solve(s1,s2,i-1,j-1,dp);
        else if(s2[j] == '*'){
            return dp[i][j] = solve(s1,s2,i-1,j,dp) || solve(s1,s2,i,j-1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};
