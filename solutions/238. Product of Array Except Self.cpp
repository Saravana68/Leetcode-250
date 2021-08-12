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
       then for every index output[i] = product/nums[i];
       05. if zero present,check whether it is one time occured or more than one time
       => if more than one time , then output[i] =0 for all elemetns
       => if only once occured then output[flag] = product and remaining output[i]= 0;
       06. return output array;
       time: O(N) space: O(1)
    */

    /* optimal approach 
       01. calculate product of whole array from left to right in output array 
       02. traverse output array from last to index 1
       03. intialize product =1
       04. for each index output[i]= output[i-1] * product,then product*= nums[i]
       05. handle boundary cases : output[0] = product
       06. return product
       time: O(n) space: O(1)
     */
        vector<int> output;
        if( nums.size() < 1)
             return output;
        int product =1;
        for(int i =0;i<nums.size();i++)
        {
            product = product* nums[i];
           output.push_back(product);
        }
        product =1;
        for(int i = nums.size()-1;i>0;i--)
        {
            output[i] = output[i-1]*product;
            product*= nums[i];
        }
        output[0] = product;
        return output;
        // first time solved: 12.08.2021
    }
};
