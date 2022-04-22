​
class Solution {
public:
    /*
       BRUTE FORCE SOLUTION :
       --------------------
       01. sort the elements in ASCENDING ORDER
       02. traverse the sorted array and do the following
       03. push first elements in answer array and push it also in unordered_set and k--
       04. In nxt iteration check num[i] is present in unordered_set 
       05. if yes ignore dont push it answer array else push it and do k -- 
       06. if K becomes zero break the loop and return answer array
       
       TIME COMPLEXTIY  : 0(NLOGN)
       SPACE COMPLEXITY : O(N) 
     
    */
    
    
    /*
        OPTIMAL SOLUTION 
        ----------------
        
        01.Refer below comments 
        
        TIME COMPLEXITY : 0(NLOGk)
        SPACE COMPLIXTY : O(N)
        
    */
    
    #define p pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> answer;
        unordered_map<int,int> mp;
        priority_queue<p,vector<p>,greater<p>> pq;
        
        // storing frequency in O(N) 
        for(int i = 0;i<nums.size();i++)
            mp[nums[i]]++;
        
        // I am used unordered_map so I can't iterate over map so I used to traverse nums [] 
        // no of push_operation in heap = no.of unique elements in given array
        // heap size will be k
        // NlogK wil be time complexity
        for(int i =0;i<nums.size();i++){
            if(mp.count(nums[i])){
            pq.push({mp[nums[i]],nums[i]});
            mp.erase(nums[i]);
            }
            if(pq.size() > k) 
                pq.pop();
        }
