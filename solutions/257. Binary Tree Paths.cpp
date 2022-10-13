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
    void solve(TreeNode* root,string str,vector<string> &ans){
        if(!root) return;
        str +=  to_string(root->val) + "->";
        if(!root->left && !root->right){
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
            return;
        }
        solve(root->left,str,ans);
        solve(root->right,str,ans);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        string str;
        solve(root,str,ans);
        return ans;
        
    }
};
