class Solution {
public:
   int subsetsumcount(vector<int>& nums,int sum,int cnt)
{
    int n=nums.size();
    long long dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(nums[i-1]==0)
                dp[i][j]=dp[i-1][j];
            else if(nums[i-1]<=j)
                dp[i][j]=dp[i-1][j] +dp[i-1][j-nums[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return pow(2,cnt)*dp[n][sum];
}
    
    int findTargetSumWays(vector<int>& nums, int S) {
