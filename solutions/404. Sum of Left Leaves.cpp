​
class Solution {
public:
    void solve(TreeNode* root, int &sum,bool flag){
        if(!root) return;
        if(!root->left && !root->right && flag){
            sum += root->val;
            return;
        }
        solve(root->left,sum,true);
        solve(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag = false;
        int sum = 0;
        solve(root,sum,flag);
        return sum;
    }
};
