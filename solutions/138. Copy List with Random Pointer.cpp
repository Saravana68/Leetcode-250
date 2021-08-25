/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
  
  /* Bruteforce approach
   01. create unordered_map<Node*,Node*> mp
   02. insert all nodes into list while inserting create dummy node as value for key
   03. now iterate over map and get the node in value 
   04. link the next and random pointers in cloned node
   05. return head of cloned linkedlist
   Time: O(N) space: O(N)
  */
​
  /* efficient approach
     01. for each node create dummy node and insert it in the orignal linkedlist
     => original  : 1 2 3 4 5
     => duplicates: 1 1 2 2 3 3 4 4 5 5
     02. for duplicate random ,check curr->random if it is null then duplicate random also NULL 
     03. if Not NULL then assign duplicate->random = curr->random->next
     04. make original nodes pointing to original only
     05. duplicates pointing to duplicates only
     06. return head of duplicate node
     TIME COMPLEXITY : O(N)  SPACE COMPLEXITY : O(1)
 */
     
​
​
class Solution {
public:
    Node* copyRandomList(Node* head) {
          if(head == NULL ) return head;
        Node *curr = head;
       // inserting duplicate nodes between original nodes
        while(curr)
        {
            Node*temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        // make duplicate nodes pointing random nodes of their original
        curr = head;
        while(curr)
        {
            curr->next->random = (curr->random!=NULL)? curr->random->next : NULL;
            curr = curr->next->next;
        }
       //deleting orignal nodes
        curr = head;
        Node* copy = head->next;
        Node * copy_head = copy;
        while(curr && copy)
