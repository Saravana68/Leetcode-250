class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        
        // assuming - 1 as majority element and their frequency as 0
        int cnt1 = 0, cnt2 = 0;
        int num1 = -1, num2 = -1;
        
        //output array 
        vector<int> ans = {};
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == num1) cnt1++;
            else if(nums[i] == num2) cnt2++;
            else if(cnt1 == 0){ cnt1 = 1; num1 = nums[i];}
            else if(cnt2 == 0){cnt2 = 1; num2 = nums[i];}
            else{cnt1--; cnt2--;}
        }
        
        // store the frequency of chosen elements.
        cnt1 = cnt2 = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == num1) cnt1++;
            else if(nums[i] == num2) cnt2++;
        }
        
        // check their frequency are greater than one third of input array size.
        int threshold_value = int(nums.size()) / 3;
        if(cnt1 > threshold_value) ans.push_back(num1);
        if(cnt2 > threshold_value) ans.push_back(num2);
        
        return ans;
    }
};
