class Solution {
public:
    bool canJump(vector<int>& nums) {
        
    /* bruteforce approach:
       01.use backtracking
       02.but it will be tle
       03. since at time of solving this problem idk dp and memoization like concepts my only bruteforce 
       approach is backtracking
    */
    
    /* optimal approach:
       01.if we need to reach end ,then any of element's value should reach end
       02.each element can go to i+ nums[i] step max
       03.at any point of iteration if i > reachable then we can't fo further this is because of zero 
       had been encountered.
       Time: O(N) space: O(1
​
    */
        int n = nums.size();
        int maxReachable = 0;
        for(int i =0; i<nums.size(); i++)
        {
            if(maxReachable < i)
                return false;
            maxReachable = max(maxReachable,i+nums[i]);
        }
        return true;
    }
};
