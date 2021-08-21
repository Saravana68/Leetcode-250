class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    //first solved : 21.08.2021
    /* BruteForce approach:
      01.run two loops if check if abs( nums[i]-nums[j]) == k
      02.if yes increment the count variable
      03.return count;
      Time: O(N2) space:o(1)
     */
        
    /* optimal approach:
      01.use hashmap
      02.insert all values of nums array and increment value as 1
      03.if duplicate found increment value of that element in map 
      04. if k == 0 then elements which appear twice will be the pair
      05. if k > 0 then find (value of key in map - k) in map of each element
      for ex : if element is 3,k=2 find (3-2) in map,result : 1 found so it will form pair
      06. we are traversing from map then how can we state that we founded value in present before that 
      current element ? it can be considered as when we at nums[i] = 1 and we search for 1+2 = 3 in remaining part
      then num[i+x] = 3 is found, hence a pair if found in map then it can be considered as valid pair
      06. Time: O(N) space : O(N);
     */
        unordered_map<int,int> mp;
        int ans =0;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto it : mp)
        {
          if(k == 0 && it.second>1)
               ans++;
          else if (k>0 && mp.count(it.first+k))
              ans++;
        }
        return ans;
    }
};
