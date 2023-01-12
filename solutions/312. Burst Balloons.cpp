class Solution {
public:
    int solve(int i,int j,int arr[],vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i;k<=j;k++){
            int cost = arr[i-1] * arr[k] * arr[j+1];
            cost += solve(i,k-1,arr,dp) + solve(k+1,j,arr,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        int arr[n+2];
        arr[0] = 1;
        arr[n+1] = 1;
        for(int i = 0;i<nums.size();i++)
            arr[i+1] = nums[i];
        //return solve(1,n,arr,dp);
        
        for(int i = n;i>=1;i--){
            for(int j = 1; j<=n;j++){
                if(i > j) continue;
                int maxi = INT_MIN;
                for(int k = i;k<=j;k++){
                    int cost = arr[i-1] * arr[k] * arr[j+1];
                    cost += dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};
