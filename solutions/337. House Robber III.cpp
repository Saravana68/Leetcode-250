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
    unordered_map<TreeNode*,int> mp;
​
    int rob(TreeNode* root) {
       
        if(!root)
            return 0;
        if(mp[root])
            return mp[root];
        
        int root_included = root->val;
        if(root->left)
            root_included += rob(root->left->left)+rob(root->left->right);
        if(root->right)
            root_included += rob(root->right->left)+rob(root->right->right);
        int root_notIncluded = rob(root->left) + rob(root->right);
        return mp[root] = max(root_included,root_notIncluded);
    }
};
