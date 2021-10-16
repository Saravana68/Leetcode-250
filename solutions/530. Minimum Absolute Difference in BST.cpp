class Solution
{
    public:
    void inorder(TreeNode* root, TreeNode*& prev, int& ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,prev,ans);
        if(prev)
            ans=min(ans,root->val-prev->val);
        prev=root;
        inorder(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root)
    {
        int ans=INT_MAX;
        TreeNode* prev=NULL;
        inorder(root,prev,ans);
        return ans;
    }
};
