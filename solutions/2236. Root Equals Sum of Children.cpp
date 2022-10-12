​
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        int sum = 0;
        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;
        return sum == root->val && checkTree(root->left) && checkTree(root->right);
    }
};
