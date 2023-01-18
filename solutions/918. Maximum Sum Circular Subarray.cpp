class Solution {
public:
    int getMaxSubarraySum(vector<int> &nums){
        int global_sum = nums[0];
        int local_sum = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            if(local_sum < 0){
                local_sum = 0;
            }
            local_sum += nums[i];
            global_sum = max(global_sum,local_sum);
            
        }
        
        return global_sum;
    }
    int getMinSubarraySum(vector<int> &nums){
        int global_min = nums[0];
        int local_min = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            if(local_min > 0)
                 local_min = 0;
            local_min += nums[i];
            global_min = min(global_min,local_min);
            
        }
        return global_min;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_subarray_sum = getMaxSubarraySum(nums);
        if(max_subarray_sum < 0) return max_subarray_sum;
        
        int totalSum = 0;
        for(int i =0;i<nums.size();i++){
            totalSum += nums[i];
            //nums[i] = - nums[i];
        }
        
        int min_subarray_sum = getMinSubarraySum(nums);
        int max_circular_sum = totalSum - min_subarray_sum;
        cout<<totalSum<<" "<<max_subarray_sum<<" "<<min_subarray_sum<<" "<<max_circular_sum<<endl;
        return max(max_subarray_sum , max_circular_sum);
    }
};
