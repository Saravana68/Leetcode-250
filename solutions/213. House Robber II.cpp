class Solution {
public:
    
    int getMaxRobbedValue (vector<int>& nums) {
        
        if(nums.size()==1)return nums[0];
        int res = 0;
        int first =nums[0];
        int second =max(nums[0],nums[1]);
        res = second;
        for(int i=2;i<nums.size();i++){
            res = max(second,first+nums[i]);
            first  = second;
            second = res;
        }
        return res;
    }
    
    
    int rob(vector<int>& nums) {
       
       int n = nums.size();
        if(n == 0)
            return 0;
        if(n ==1) 
            return nums[0];
        if(n ==2)
            return max(nums[0],nums[1]);
        
       vector<int> numsA (nums.begin(),nums.end()-1);
       vector<int> numsB (nums.begin() +1,nums.end());
        
        return max(getMaxRobbedValue(numsA),getMaxRobbedValue(numsB));
        
    }
};
