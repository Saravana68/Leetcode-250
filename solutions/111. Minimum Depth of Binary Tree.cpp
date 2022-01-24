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
    int res = INT_MAX;
    void getMinDepth(TreeNode* root,int count){
        
        if(!root) return ;
        
        if(!root->left && !root->right)
        {
            res = min(res,count);
            return;
        }
        getMinDepth(root->left,count+1);
        getMinDepth(root->right,count+1);
        
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        getMinDepth(root,1);
        return res;
    }
};
