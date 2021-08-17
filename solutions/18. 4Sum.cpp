class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
    //first time solved : 18.08.2021
        
    /* Bruteforce :
      01.using four loops and traversing the input array
      02.form sum and check sum ==  target 
      03. if yes store the answer in set< vector<int> > to avoid duplicates
      04. after coming out of loops insert values from set to output array
      05. return output arrau
      Time: O(N4*logn) // logn for set
      space: O(N);
    */
    
    /* optimal
      01. we can reduce inner three loop using two pointer method and reduce the time by one loop less
      time: O(N3*logN) // N3 for two loops and one two pointer
      space: O(N)
    */
          sort(nums.begin(),nums.end());
          set< vector<int> > s;
          int n = nums.size();
          
          for(int i =0 ;i < n-3;i++)
          {
              for(int j =i+1; j< n-2; j++)
              {
                  int left = j+1;
                  int right = n-1;
                  while(left<right)
                  {
                     long long int sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[left]+(long long)nums[right];
                      if( sum == target)
                      {
                          s.insert({nums[i],nums[j],nums[left],nums[right]});
