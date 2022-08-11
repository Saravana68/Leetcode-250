class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto x : nums) total += x;
        int left = 0;
        
        for(int i =0;i<n;i++){
            
            int right = total- nums[i];
            if(left == right) return i;
            left += nums[i];
            total = total - nums[i];
        }
        return -1;
    }
};
