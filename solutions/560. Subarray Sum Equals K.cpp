class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int res = 0;
        int curr_sum = 0;
        for(int i =0;i<nums.size();i++){
            curr_sum += nums[i];
            if(mp.count(curr_sum - k)){
                res += mp[curr_sum -k];
            }
            mp[curr_sum]++;
        }
        return res;
    }
};
