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
   
