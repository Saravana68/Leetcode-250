class Solution {
public:
 int pivotIndex(vector<int>& nums) {
     
     
 /* Bruteforce: 
    01.using one outer loop traverse array elements. for each element nums[i]
    02. intialize prefsum =0 and sufSum =0 inside this loop
    03. using another loop to traverse from o to i-1 for calculating prefsum
    04. use another loop to traverse from i+1 to n for calculating sufsum
    05. if (prefSum == sufSum)  return i and break; 
    06. if no  answer found return -1;
    Time: O(n2) ; one outer loop and two inner loop nested. space: o(1);
  */
  
  /* better : 01
     01.calculating prefixSum array and suffixsum array
     02. if index is to be pivot then sum from 0 to i should be equal to sum from
     i to n; Ex: [1,7,8,6,5,6] pivot_index: 3 => element: 6
     03.sum from o to 3rd index: 17 , sum from 3rd index to last index = 17
     04.by using this technique after calculating prefSum and sufSum traverse these 
     two array in one loop, at any point prefSum[i] == sufSum=[i] then return i
     time: O(n) space: O(n);
  */
   
  /* optimal:
     01. optimizing the space complexity
     02. calculate the total sum of array and store it in a variable
     03. intiialize a comp variable as zero
     04. traverse the input array and reduce nums[i] from totalSum also add nums[i]
     to comp variable 
     05.if at any point totalSum == comp variable return i 
     06. if match not found return -1
  */
     int size = nums.size();
     int totalSum =0;
     for(auto x: nums)
          totalSum+=x;
     int comp =0;
     for(int i = 0;i<nums.size();i++)
     {
         totalSum -= nums[i];
         if(totalSum == comp ) return i;
         comp += nums[i];
     }
     return -1;
        
    }
    // first time solving : 5.01.2021
    //second time solving: 10.08.2021
};
