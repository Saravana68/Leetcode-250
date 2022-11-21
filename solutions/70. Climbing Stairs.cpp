class Solution {
public:
    int solve(int n, vector<long long int> &dp){
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int prev2 = 1;
        int prev = 1;
        int curr = 0;
        for(int i = 2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
