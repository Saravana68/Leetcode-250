/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
​
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
​
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
​
class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
       Node* rowHead = NULL,*rowTail = NULL;
       while(curr){
           vector<Node*> children = {curr->left,curr->right};
           for(auto temp : children){
               if(!temp)
                   continue;
               if(!rowHead){
                   rowHead = rowTail = temp;
               }
               else{
                   rowTail->next = temp;
                   rowTail = rowTail->next;
               }
           }
           curr = curr->next;
           if(!curr){
               curr = rowHead;
               rowHead = rowTail = NULL;
           }
       }
        return root;
    }
};
