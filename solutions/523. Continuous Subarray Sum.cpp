class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr_sum = nums[0];
        mp[curr_sum % k] = 0;
        
        for(int i = 1;i<nums.size();i++){
            curr_sum += nums[i];
            if(curr_sum % k == 0) return true;
            if(mp.count(curr_sum % k)){
                if(i - mp[curr_sum % k] > 1) return true;
            }
            else mp[curr_sum % k] = i;
        }
    return false;
    }
    
};
