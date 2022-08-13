/* 1st Intuition -
   154 / 265 test cases passed. then got answer wrong
*/
​
/* Proper intution - 
   -> start from last, values should be increasing in order from last,
   -> if arr[i] < arr[i+1] then i is the we need to fix
   -> find next smallest element for arr[i] from index i+1. let it be j
   -> swap(arr[i],arr[j]);
   -> reverse array starting from index i +1
   
   TIME COMPLEXITY : O(N) + O(N) + O(N)
   SPACE COMPLEXITY : O(1)
   Date solved : 13.08.2022
 */
​
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int ind = -1;
       for(int i = nums.size()-1;i>0;i--){
           if(nums[i] > nums[i-1]){
               ind = i-1;
               break;
           }
       }
       if(ind == -1) {
           reverse(nums.begin(),nums.end());
           return;
       }
       int temp = ind+1;
       for(int i = ind+1;i<nums.size();i++){
           if(nums[i] > nums[ind] && nums[i]<= nums[temp])
               temp = i;
       }
       swap(nums[ind],nums[temp]);
       reverse(nums.begin() + ind+1,nums.end());
       
    }
};
