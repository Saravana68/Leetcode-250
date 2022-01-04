class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        int arr[n+2];
        
        arr[0] = 1;
        
        arr[n+1] = 1;
        
        for(int i = 1; i <= n; i++)
            arr[i] = nums[i-1];
        
        int dp[n+2][n+2];
        memset(dp, 0, sizeof(dp));
        
        for(int length = 1; length <= n; length++)
        {
            for(int left = 1; left <= (n - length + 1); left++)
            {
                int right = left + length - 1;
                
                for(int i = left; i <= right; i++)
                {
                    dp[left][right] = max(dp[left][right], (arr[left-1] * arr[i] * arr[right+1]) + dp[left][i-1] + dp[i+1][right]);
                }
            }
        }
        
        return dp[1][n] ;
    }
};
