class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
    /* Bruteforce: 
       01. traversing the array from left to right;
       02. intialize two variable left_product and right_product;
       03. at each index i , calculate product from 0 to i -1 in left_product and calculate from i+1 to n in 
       right_product
       04. then multiply these two variables and update it vector<int> answer
       Time: O(N2)  space: O(1)
    */
     
    /* better approach :01
       01. intialize two array named left_product and right_product;
       02. calculate product from left and store the each value in left_product array
       03. calculate product from last element to first and store each value in right_product array
       04. now traverse the input array at each index i , multiply left_product[i-1] * right_product[i+1]
       05. update the value in answer array
       06. handle the boundary cases such that output[0] = right_product[1] and output[n-1] = left_product[n-2]
       Time: O(N) space: O(N)
     */
      
    /* better approach :02
       01.intitalize only one product variable
       02. calculate whole product of array in that variable 
       03. while calculating product , initialize check =0
          a. if zero encountered, do check-- and store the index of 0 in flag variable only if (flag == -1)
          because if morethan one zero occured then all values of output array is surely zero but only if zero 
          occured then we need to insert array product at index of output array where zero occurs in input array
          and fill remaining indexes as zero . for that we need index of zero where it occurs in input array. 
          b. omit mulitplying product with zero if encountered
       04. traverse output array, if zero not present in input array (i.e) check == 0 still
