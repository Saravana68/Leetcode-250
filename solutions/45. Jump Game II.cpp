/* RECURSION + MEMOIZATION 
   -----------------------
   TIME COMPLEXITY : O(N) - Every subproblem solved only once because of storing answer in dp[]
   SPACE COMPLEXITY : O(N) + O(N) using dp[] + some auxillary stack space required thats why.
*/ 
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
​
/* TABULATION
   ----------
   In recursion we started from index 0 now start from index n-2
   Index n-1 is base case because we dont want jump further from target  so dp[n-1] = 0
   if nums[i] == 0 we can't jump further. 
   TIME COMPLEXITY : O(N)
   SPACE COMPLEXITY : O(N)
*/
class Solution {
public:
​
int jump(vector<int>& nums) {
        int n = nums.size();        
    
        vector<int> dp(n+1,0);
        dp[n-1] = 0;  // base case
        
        for(int i = n-2;i>=0;i--){
            
            if(nums[i] == 0 ) { // can't reach target from this cell, so discard this path
                dp[i] = INT_MAX - 10000; // 1 + dp[i+k] if dp[i+k] is 1e9 addition not possible  thats why instead of INT_MAX some meaningful value stored
                 continue;
              }
            int ans = INT_MAX;
            int limit = nums[i];
            for(int k = 1;k<=limit;k++){
                if(i+k >=n) break;
                int temp = 1+dp[i+k];
                ans = min(ans,temp);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
