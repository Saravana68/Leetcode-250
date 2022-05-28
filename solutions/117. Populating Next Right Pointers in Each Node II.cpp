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
