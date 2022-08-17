class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int majority = nums[0];
        int count = 1;
        for(int i =1;i<nums.size();i++){
            if(nums[i] == majority) count++;
            else count--;
            if(count == 0){
                count = 1;
                majority = nums[i];
            }
        }
        count = 0;
        for(int i =0;i<nums.size();i++)
            if(nums[i] == majority) count++;
        
        if(count > nums.size()/2) return majority;
        return -1;
    }
};
