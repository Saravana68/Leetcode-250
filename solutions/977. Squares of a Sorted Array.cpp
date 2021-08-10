class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    
  /* Bruteforce:
     01. traverse the array and calculate square value for each element in array
     02. sort the array 
     03. time : O(Nlogn)  space: O(n) for sorting
  */
 
  /* optimal:
     01.since we know the size of output array we can insert values from last
     02.ignore the sign of the element,because after calculatin pow sign always +ve
     03.handle the case middle element if size of array is odd
     time: o(n)  space: O(1);
  */
        
       int n  = nums.size();
        vector<int> answer(n,0);
        if(n == 1)
        {
            answer[0] = pow(nums[0],2);
            return answer;
        }
        
        int left =0;
        int right= n -1;
        int index = n-1;
        while(left<=right)
        {
           if(abs(nums[left]) < abs(nums[right]))
              {
                 answer[index] = pow(nums[right],2);
                 right--;
              }
            else if(abs(nums[left]) > abs(nums[right]))
              {
                  answer[index] = pow(nums[left],2);
                  left++;
              }
             else if(abs(nums[left]) == abs(nums[right]))
              {
               answer[index] = pow(nums[left],2);
               index--;
               if(index == -1) break;
               answer[index] = pow(nums[right],2);
               left++;
               right--;
              }
            index--;
        }
    return answer;
    
    }
};
