/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
​
/* 
class Solution {
public:
    // Inorder Traversal
    void inorder(TreeNode* root, string& str)
    {
        if(!root)
        {
            str += '$';
            return;
        }
        
        inorder(root->left,str);
        str += to_string(root->val);
        inorder(root->right,str);
    }
    
    // Preorder Traversal
    void preorder(TreeNode* root, string& str)
    {
        if(!root)
        {
            str += '$';
            return;
