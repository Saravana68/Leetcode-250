*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        curr = head;
        while(curr && curr->next){
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        curr = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;
        while(curr && copy){
            curr->next = curr->next!=NULL ? curr->next->next : NULL;
            copy->next = copy->next!= NULL ? copy->next->next : NULL;
            curr = curr->next;
            copy = copy->next;
        }
    
        return copyHead;
    }
};
​
​
