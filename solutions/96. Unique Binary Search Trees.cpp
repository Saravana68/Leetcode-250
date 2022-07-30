class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n <=1) return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = 0;
        for(int i =0;i<n;i++)
            ans += f(i,dp)*f(n-i-1,dp);
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        dp[0]= 1;
        dp[1] = 1;
        return f(n,dp);
    }
};
