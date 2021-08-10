class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0 || n == 1)
             return n;
       
        int index =1;
        int check = nums[0];
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]!= check)
            {
                 nums[index] = nums[i];
                 index++;
                check = nums[i];
            }
        }
        return index;
        }
    
};
