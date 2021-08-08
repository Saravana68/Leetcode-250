class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //    
        // brute force will be using loops and generating all subarrays  
        // if match find increment counter and return counter finally
        // time complexity:  O(n2) space : O(1);
        
        //better approach will be using unordered_map
        // calculate prefix sum for each index from start of the array
        // at each index search the ( prefixsum[i] - k ) present in unordered_map
        //if present increase counter and  mp[prefix-sum]++
  
        
        // previously used unordered_set<int> but failed for [ 0,0,0,0,0] and k = 0;
        // my output was = 9 but actual answer is = 15 
        // I didn't think about what if zeros came in middle.
        
        int n = nums.size();
        unordered_map<int,int> mp;
        int prefix_sum = 0;
        int count = 0;
        
        for(int i =0;i<n;i++)
        {
            prefix_sum += nums[i];
            if(prefix_sum == k)
                 count++;
            if(mp.find(prefix_sum - k)!= mp.end())
                count += mp[prefix_sum -k];
            
            mp[prefix_sum]++;
​
        }
