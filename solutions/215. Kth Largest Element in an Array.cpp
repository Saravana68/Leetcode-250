class Solution {
public:
  /*
     NAIVE APPROACH
     ---------------
     01. Sort the array in O(NLOGN) time
     02. return array [size-k] element
     
     TIME : O(NLOGN)      SPACE : O(N)
     ------               ------
     
     
     EFFICIENT APPROACH
     ------------------
     01. Create Min-heap of size K
     02. insert first K elements from array
     03. start from Kth index and traverse upto last element in array
     04. while traversing check arr[i] > minHp.top() if yes do POP() in minHP and insert arr[i]
     05. once traversal completed return MinHp.top()
     
     TIME: O(NLOGN)      SPACE: O(K) 
     -----               -----
     
  */
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int> > minHp;
        
        for(int i =0;i<k;i++)
            minHp.push(nums[i]);
        
        for(int i =k;i<nums.size();i++){
            if(nums[i] >= minHp.top()){
                minHp.pop();
                minHp.push(nums[i]);
            }
        }
        return minHp.top();
    }
};
