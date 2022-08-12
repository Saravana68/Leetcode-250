class Solution {
public:
    int f(int idx , int dest, vector<int> &nums,vector<int> &dp){
        if(idx >= dest) return 0;
        if(nums[idx] == 0) return INT_MAX;
        if(dp[idx]!= -1)
            return dp[idx];
        int limit = nums[idx];
        int ans = INT_MAX;
        for(int i =1;i<=limit;i++){
            int temp = f(idx+i,dest,nums,dp);
            temp= temp == INT_MAX ? INT_MAX : 1+temp;
            ans = min(ans,temp);
        }
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(0,n-1,nums,dp);
    }
};
