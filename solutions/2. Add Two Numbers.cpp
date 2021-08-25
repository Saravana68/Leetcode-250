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
