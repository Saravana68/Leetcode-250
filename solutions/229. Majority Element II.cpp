class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = -1 , elem2 = -1;
        int count1 = 0, count2 = 0;
        
        for(int i =0;i<nums.size();i++){
            
            if(nums[i] == elem1) {count1++;}
            else if(nums[i] == elem2) {count2++;}
            else if(count1 == 0 ){elem1 = nums[i]; count1++; }
            else if(count2 == 0) {elem2 = nums[i]; count2++; }
            else{count1--; count2--;}
        }
        
        count1 = 0; count2 = 0;
        for(int x : nums){
            if(x == elem1) count1++;
            else if(x == elem2) count2++;
        }
        vector<int> ans;
        if(count1 > nums.size() / 3) ans.push_back(elem1);
        if(count2 > nums.size() / 3) ans.push_back(elem2);
        return ans;
    }
};
