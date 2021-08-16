class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
    /* Bruteforce approach:
      01.we can find duplicate of existing input array using boolean frequency array of two  
      traversals or using unordered_set and push_back elements if already found
      time: O(N) and space: O(N)
    */
     
    /* optimal approach:
       01. given that array consists of elements from 1 to n (i.e) all positive from range 1<=n
       02. using this fact we can use array elements as index and mark nums[index]*= -1
       03. if again same element encountered with -ve value this element is already present 
       04.so push_back that element into output array
       05.return output array
       Time: O(N) space: O(1);
    */
    
    /* first time solved :  16/08/2021  17:29   Accepted    48ms    33.6 MB cpp
       Runtime: 48 ms, faster than 79.36% of C++ online submissions for Find All Duplicates in an Array.
       Memory Usage: 33.6 MB, less than 73.34% of C++ online submissions for Find All Duplicates in an Array.
    */
        vector<int> answer;
        for( auto x : nums )
        {
            x= abs(x);
            if( nums[x-1] < 0) 
                 answer.push_back( abs(x));
            else 
                nums[x-1]*= -1;
        }
        return answer;
    }
};
