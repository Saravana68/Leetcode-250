            totalNodes++;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            ListNode* currHead = curr;
            int remNodes = totalNodes - Nodes;
            if(remNodes >= level){
              
                if(level & 1){
                    for(int i =0;i<level && curr;i++){
                        Nodes++;
                        prevHead = curr;
                        curr = curr->next;
                    }
                    level++;
                }
                else{
                    ListNode* prev = NULL;
                    for(int i =0;i<level && curr;i++){
                        Nodes++;
                        ListNode* next = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = next;
                        
                    }
                    level++;
                    prevHead->next = prev;
                    prevHead = currHead;
                    currHead->next = curr;
                }
            }
            else {
                ListNode* prev = NULL;
                if(remNodes % 2 == 0){
                    
                while(curr){
                    ListNode* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                  }
                    prevHead->next = prev;
                }
                break;
            }
        }
        return head;
    }
};
