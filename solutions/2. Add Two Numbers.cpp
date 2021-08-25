      10. return result head
     TIME: O(L1 + L2)  SPACE : O(1)
  */
     
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
             
​
     ListNode * result = new ListNode();
     ListNode * temp = result;
     int carry = 0;
​
        
      while(l1 ||  l2 ){
         int sum =0 ;
         if(l1)
          {
             sum+= l1->val;
             l1= l1->next;
              
          }
          if(l2)
          {
              sum+= l2->val;
              l2 = l2->next;
          }
          sum+=carry;
          carry = sum /10;
          sum = sum% 10;
         
         result->next = new ListNode(sum); 
          result = result->next;
          
      }
     
    
    if(carry>0)
    { 
        result->next = new ListNode(carry);
        result = result->next;
    }
  
    
    
    return temp->next;
        
        
               
          
    }
};
