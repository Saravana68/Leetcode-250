/**
 * DEFINITON OF SINGLY LINKEDLIST
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* BRUTEFORCE APPROACH
    01. add values in each nodes in two strings
    02. convert strings into integer
    03. add the value
    04. reverse the value
    05. extract last digit and insert into new node 
    06. create new linkedlist by extracting last digit until value == 0
   TIME COMPLEXITY  : O(N) SPACE COMPLEXITY: O(N)
  */

  /* OPTIMAL APPROACH
      01. intiailize variable carry =0
      02. traverse two nodes until both of them become NULL
      03. inside loop intialize sum =0 
      04. add value in l1 if it not NULL
      05. add value in l2 if it not NULL
      06. add carry to sum ( intially carry =0 )
      07. if sum >9  then store the remainder in carry
      08. after list both became NULL check carry is NULL
      09. if yes create new node and insert carry in node->data
      10. return result head
     TIME: O(L1 + L2)  SPACE : O(1)
  */
     
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
             

     ListNode * result = new ListNode();
     ListNode * temp = result;
     int carry = 0;

        
      while(l1 ||  l2 ){
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
