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
        Node* head = NULL, *tail = NULL;
        while(curr){
            vector<Node*> child = {curr->left,curr->right};
            for(auto temp : child){
                if(!temp) continue;
                if(!head) head = tail = temp;
                else {
                    tail->next = temp;
                    tail = tail->next;
                }
            }
            curr = curr->next;
            if(!curr){
                curr = head;
                head = tail = NULL;
            }
        }
        return root;
    }
};
