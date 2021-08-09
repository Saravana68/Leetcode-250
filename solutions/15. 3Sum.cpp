class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
    
     /* first time solving: 09.08.2021
     
      Brute force approach will be: using three loops to traverse the array 
      to find the required the output. after finding three indices where 
      i!= j!= k , store the answer in result vector and also
      we need to insert theses three indices in hashmap
      
      in next iteration if we found new three indices ,we need to check 
      whether atleast two indices are not seen/encountered for answer before.
      i.e search the selected three indices in hashmap, if more than one 
      index found in map then we can't count current three as valid indices because 
      duplicates are not allowed
      
      testcase 1 : [-1,0,1,2,-1,-4]
      output:      [[-1,-1,2],[-1,0,1]]
      here, second triplet is [-1,0,1] indices are: 0,1,2
      insert these indices in hashmap and run algo again
      second triplet we found : [0,-1,1] indices are: 1,2,4
      if we search these three indices in map we found atmost two indices 
      so these triplets are not valid so that they are not in actual output */
        
     /* better approach : 01
      1.sort that array
      2.select one index i, use two pointer approach to find remaining two indices.
      3.handle duplicates inside while loop 
      time :   O(n^2)        space : o(1);
      */
      
       int n = nums.size();
        if(n<3) return {};
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< n-2;i++)
        {
            if(i == 0 ||  nums[i] != nums[i-1])
            {
               int j = i+1, k= n-1;
               while(j<k)
               {
                   int sum = nums[j] + nums[k] + nums[i];
                   if( sum == 0) 
                   {
                       result.push_back( {nums[i],nums[j],nums[k]});
                       while(j<k && nums[j] == nums[j+1]) j++;
                       while(j<k && nums[k] == nums[k-1]) k--;
                       j++;
                       k--;
                   }
                   else if(sum>0) k--;
                   else j++;
               }
            }
        }
        return result;
        
    }
};
