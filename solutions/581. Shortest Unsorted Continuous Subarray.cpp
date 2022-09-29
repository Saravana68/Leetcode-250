class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                mini = min(mini,nums[i]);
               
            }
        }
        for(int i =nums.size()-2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                maxi = max(maxi,nums[i]);
                
            }
        }
        if(mini == INT_MAX && maxi == INT_MIN) return 0;
        int start = 0;
        for(;start<nums.size();start++){
            if(nums[start] > mini) break;
        }
        int end = nums.size() - 1;
        for(;end>=0;end--){
            if(nums[end] < maxi) break;
        }
        return end - start +1;
    }
};
