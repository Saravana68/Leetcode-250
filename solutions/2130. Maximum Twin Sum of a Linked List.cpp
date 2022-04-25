/* 
   BRUTEFORCE APPROACH
   -------------------
   01.store all node values in vector 
   02. traverse vector and find sum using given condition
   
   TIME COMPLEXITY : O(N)   SPACE COMPLEXITY: O(N)
  
 */
   
class Solution {
public:
     int max(int a ,int b){
         
         if(a >b) 
             return a;
         return b;
     }
    
    int pairSum(ListNode* head) {
        
        if(!head->next)
          return head->val;
    
        vector<int> list;
         
        ListNode* curr = head;
        while(curr){
            
            list.push_back(curr->val);
            curr = curr->next;
        }
        
        int len = list.size();
        long long int sum =0;
        for(int i = len-1;i>=len/2;i--){
