class Solution {
public:
    int solve(int n)
    {
        int rev=0;
        int rem;
        while(n!=0)
        {
           rem=n%10;
            rev=(rev*10)+rem;
            n=n/10;
        }
        return rev;
        
    }
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<long long ,long long> mp;
        for(int i = 0;i<nums.size();i++){
          count += mp[nums[i] - solve(nums[i])];
          mp[nums[i] - solve(nums[i])]++;
        }
        return count%1000000007;
    }
};
