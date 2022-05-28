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
        if(!root) return NULL;
        queue<Node*> q;
        Node* curr = root;
        q.push(root);
        while(q.size()){
            Node* temp = NULL;
            int size = q.size();
            for(int i =0;i<size;i++){
                Node* root = q.front(); q.pop();
                if(i != 0){
                    temp->next = root;
                }
                temp = root;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
