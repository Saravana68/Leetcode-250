class Solution {
public:
    
    // Recursion + Memoization - TLE
    int doSolveKnapSack(int i,vector<int> &costs, int coins,vector<vector<int>> &dp){
        if(coins == 0) return 0;
        if(i < 0) return 0;
        if(dp[i][coins] != -1) return dp[i][coins];
        int exclude = doSolveKnapSack(i-1,costs,coins,dp);
        int include = INT_MIN;
        if(costs[i] <= coins)
            include = 1 + doSolveKnapSack(i-1,costs,coins - costs[i],dp);
        
        return dp[i][coins] = max(exclude,include);
    }
    // Tabulation - TLE  19 / 63 test cases passed.
    int doSolveKnapSack(vector<int> &costs, int coins){
        int n = costs.size();
        vector<vector<int>> dp(n,vector<int>(coins+1,0));
        
        for(int j =0;j<=coins;j++)
            if(costs[0] <= j) dp[0][j] =1;
        for(int i = 1;i<n;i++){
            for(int j = 1;j<=coins;j++){
                
                int exclude = dp[i-1][j];
                int include = INT_MIN;
                if(costs[i] <= j)
                    include = 1+ dp[i-1][j - costs[i]];
                
                dp[i][j] = max(include,exclude);
            }
        }
        return dp[n-1][coins];
    }
    
    // Greedy
    int doSolve(vector<int> &costs,int coins){
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int result = 0;
        for(int cost : costs){
            if(cost <= coins){
                result++;
                coins = coins - cost;
            }
        }
        return result;
    }
    
    int maxIceCream(vector<int>& costs, int coins) {
        return doSolve(costs,coins);
    }
};
