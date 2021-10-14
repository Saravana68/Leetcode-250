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
class Solution {
public:
    int sum =0;
    void sumofLeaves(TreeNode * root, bool isleft)
    {
        if(isleft && !root->left && !root->right){
            sum += root->val;
            return;
        }
        if(root->left) sumofLeaves(root->left,true);
        if(root->right) sumofLeaves(root->right,false);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        sumofLeaves(root,false);
        return sum;
    }
  
};
