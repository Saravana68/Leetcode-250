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
    void solve(TreeNode* root,int &target, int sum,bool &flag){
        if(!root) return;
        sum += root->val;
        if(!root->left && !root->right){
            cout<<sum<<" ";
            if(sum == target) flag  = true;
            return;
        }
        solve(root->left,target,sum,flag);
        solve(root->right,target,sum,flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool flag = false;
        solve(root,targetSum,sum,flag);
        return flag;
    }
};
