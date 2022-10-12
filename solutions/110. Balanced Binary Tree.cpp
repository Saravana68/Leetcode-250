class Solution {
public:
    int solve(TreeNode* root, bool & isBalanced){
        if(!root) return 0;
        int left = solve(root->left,isBalanced);
        int right = solve(root->right,isBalanced);
        
        int diff = abs(right - left); 
        if(diff > 1) isBalanced = false;
        return max(left,right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        solve(root,isBalanced);
        return isBalanced;
    }
};
