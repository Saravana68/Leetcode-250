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
   
  /* bounds_error
     if(index = -1 ) break ; written in line : 48?
     => dry run the testcase: [7,-3,2,3,11] 
     => in last iteration where left and right values are : 02
        a. condition falls in third if condition
        b. after 4^2 = 16 inserted in index =0 , index -- occurs 
        c. this leads to bounds_error where negative index is not acceptable
        d. for that if (index == -1 ) that means we have to inserted all the input array and unneccesarily we're trying to insert one element again in negative index
        e. so we break the loop
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
               if(index == -1) break; // handling the bounds error. 
               answer[index] = pow(nums[right],2);
               left++;
               right--;
              }
            index--;
        }
    return answer;
    
    }
};
