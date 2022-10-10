class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       unordered_map<long long,long long> mp;
        long long  count = 0;
       for(int i = 0;i<nums.size();i++){
           count += mp[i-nums[i]];
           mp[i - nums[i]]++;
       }
       long long total = (1L*nums.size() * (nums.size()-1))/2;
        return total - count;
    }
};
