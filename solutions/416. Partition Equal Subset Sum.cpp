        bool notTaken = solve(idx -1, nums,target);
        bool taken = false;
        if(nums[idx] <= target)
            taken = solve(idx-1,nums,target - nums[idx]);
        
        return taken || notTaken;
    }
    // Recursion + Memoization  TIME : O(N*Target) SPACE : O(N) + O(N*target)
    bool solve(int idx, vector<int> &nums,int target,vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return nums[0] == target;
        if(dp[idx][target] != -1) return dp[idx][target];
        bool notTaken = solve(idx -1, nums,target,dp);
        bool taken = false;
        if(nums[idx] <= target)
            taken = solve(idx-1,nums,target - nums[idx],dp);
        
        return dp[idx][target] = taken || notTaken;
    }
    // Tabulation 
    bool solve(vector<int> &nums,int target){
        cout<<"Tabulation"<<endl;
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        
        for(int i = 0; i<n;i++)
              dp[i][0] = true;
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        
        for(int i =1 ;i<n;i++){
            for(int j = 1;j<=target;j++){
                bool notTaken = dp[i-1][j];
                bool taken = false;
                if(nums[i] <= j) 
                    taken = dp[i-1][j - nums[i]];
                
                dp[i][j] = taken || notTaken;
            }
        }
        return dp[n-1][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int x : nums) totalSum += x;
        if(totalSum & 1) return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums,target);
    }
};
