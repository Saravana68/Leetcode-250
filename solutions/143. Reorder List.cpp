/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
​
​
​
public:
    ListNode * getReversed(ListNode* head)
    {
        ListNode * prev = NULL;
        while(head)
        {
            ListNode * next = head->next;
            head->next = prev;
            prev = head;
            head = next;
         
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
​
        ListNode* first = head->next;
        ListNode* second = head;
        
        ListNode * dummy = head;
        ListNode * dummyhead = dummy;
        
        while(first!= NULL && first->next != NULL)
        {
            first = first->next->next;
            second = second->next;
        }
        
        ListNode * rem = second->next;
        second->next = NULL;
        rem = getReversed(rem);
        while(rem)
        {
            ListNode * temp = dummy->next;
            ListNode * flag = rem->next;
            dummy->next = rem;
            rem->next = temp;
            dummy = temp;
            rem = flag;
        }
       
    }
};
​
​
