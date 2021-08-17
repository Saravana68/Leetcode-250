class Solution {
public:
    int findDuplicate(vector<int>& nums) {
​
    
    //First time Solved: dont know but I've solved it using brute force appraoch
    // second time revisted today-18.06.2021 after solving leetcode 442
    // used the same approach it worked and it became 6 ms, faster than 95.66% of C++ online submissions 
​
    /* bruteforce: 01
      01.sort the array and find element at index[i] == index[i-1]
      02.if found yes index[i];
      Time: O(NlogN) space:O(1)
    */
    
    /* better 01 :
      01. using unordered_set insert elements from array
      02. traverse each element in array and check if it find in unordered_set if yes return nums[i
      03.else insert(nums[i]) in unordered_set
      Time: O(N) space: O(N)
    */
    
    /* optimal: best solution
       01.values are from 1 to n
       02.so each element's index is minus 1 from its value
       03.traverse the array and mark current element'index as negative
       04.when we again access same index and if it is negative means we've already visited that index
       05. so return that nums[i]
       Time: O(N) space: O(1)
     */
       
  
     auto result = INT_MAX;
     for(auto x : nums)
     {
          x = abs(x);
         if(nums[x]< 0 ) 
         {
            result = abs(x);
             break;
         }
         else
             nums[x]*= -1;
    }
        return result;
    
    }
};
    
​
