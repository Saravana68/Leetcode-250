  
  TIME : O(NLOGN)             SPACE : O(N)
  --------------              ------------
  
  EFFICIENT APPROACH
  ------------------
  
  01. create a pair<int,int> to store node->val and index of that node present
  02. create minHeap of type Pair<int,int>
  03. insert head of all linkedlist in vector
  04. pop the top element from minheap and using index from pair insert next element from that row
  05. do this until minHeap is empty
  
  TIME : O(NKLOGK)             SPACE : O(K)
  ----------------             ------------
​
​
*/
​
class Solution {
public:
    #define p pair<int,int>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<p,vector<p>,greater<p> > pq;
        ListNode * head = new ListNode(100);
        ListNode* tail = head;
        
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1) 
            return lists[0];
        
        for(int i =0;i<lists.size();i++){
           if(lists[i])
               pq.push({lists[i]->val,i});
        }
        
        while(pq.size()){
            auto temp = pq.top();
            pq.pop();
            int idx = temp.second;
            lists[idx] = lists[idx]->next;
            if(lists[idx])
                pq.push({lists[idx]->val,idx});
            ListNode* dummy = new ListNode(temp.first);
            tail->next = dummy;
            tail = tail->next;
        }
        return head->next;
    }
};
