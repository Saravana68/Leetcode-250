/* 
only last part/level should be taken care.
reversing the last part depends on no.of nodes present in that part
how to determine whether it is last part or not ? 
 if no of nodes is < level then we're at last level. 
 -> so we should check no of nodes in that level is even or not.
 -> if even reverse it else return it as it is.
*/
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
      
        int totalNodes = 0;
        int Nodes = 0;
        int level  = 1;
        
        ListNode* curr = head;
        ListNode* prevHead = head;
        
        while(curr){
            totalNodes++;
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr){
            
            ListNode* currHead = curr;
            int remNodes = totalNodes - Nodes;
            if(remNodes >= level)
            {
                   if(level & 1){
                      for(int i =0;i<level && curr;i++){
                            Nodes++;
                            prevHead = curr;
                            curr = curr->next;
                          }
                        level++;
                    }
                    else
                    {
                        ListNode* prev = NULL;
                        for(int i =0;i<level && curr;i++){
                            Nodes++;
                            ListNode* next = curr->next;
                            curr->next = prev;
                            prev = curr;
                            curr = next;
                            }
​
                        level++;
                        prevHead->next = prev;
                        prevHead = currHead;
                        currHead->next = curr;
