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
​
    /* optimal approach 
       01. calculate product of whole array from left to right in output array 
       02. traverse output array from last to index 1
       03. intialize product =1
       04. for each index output[i]= output[i-1] * product,then product*= nums[i]
       05. handle boundary cases : output[0] = product
       06. return product
       time: O(n) space: O(1)
     */
    
        int zeroes = 0;
        int product = 1;
        int flag = -1;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroes++;
                if(zeroes == 1) flag = i;
            }
            else{
                product = product*nums[i];
            }
        }
        vector<int> ans(nums.size(),0);
        if(zeroes >=2) return ans;
        else if(zeroes == 1) {
            ans[flag] = product;
            return ans;
        }
        else{
            for(int i =0;i<ans.size();i++){
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};
