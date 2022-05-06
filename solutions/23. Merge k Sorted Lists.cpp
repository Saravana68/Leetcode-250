/* 
​
  NAIVE APPROACH                            09.11.2021
  --------------
  
  01. copy all nodes into new vector
  02. sort that vector using comparator function
  03. traverse the vector and create new linkedlist using nodes in vector
  04. return head
  
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
  
*/
​
​
class Solution {
public:
    #define p pair<int,ListNode*>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;
        if(k ==1) return lists[0];
       priority_queue<p,vector<p>,greater<p>> pq;
        for(int i =0;i<k;i++){
            if(lists[i])
             pq.push({lists[i]->val,lists[i]});
        }
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while(pq.size()){
            auto temp = pq.top(); pq.pop();
            tail->next = temp.second;
            tail = tail->next;
            
            if(temp.second->next){
                temp.second = temp.second->next;
                pq.push({temp.second->val,temp.second});
            }
        }
        return head->next;
    }
};
