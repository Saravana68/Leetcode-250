​
/* 
   BRUTEFORCE APPROACH 
   -------------------
   
   
class Solution
{
    public:
    void dfs(Node* root, vector<Node*> &Nodes){
        if(!root) return;
        
        Nodes.push_back(root);
        dfs(root->left,Nodes);
        dfs(root->right,Nodes);
    }
    void flatten(Node *root)
    {
       vector<Node*> Nodes;
       dfs(root,Nodes);
       Node* head = Nodes[0];
       for(int i =1 ;i<=Nodes.size()-1;i++){
           head->right = Nodes[i];
           head->left = NULL;
           head = head->right;
       }
       root = head;
    }
};
​
​
​
*/
​
​
class Solution {
public:
   TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
