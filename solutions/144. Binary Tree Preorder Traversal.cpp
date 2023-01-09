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
    void preorder(vector<int> &NodeList,TreeNode* root){
        if(!root) return;
        NodeList.push_back(root->val);
        preorder(NodeList,root->left);
        preorder(NodeList,root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
     vector<int> NodeList = {};
     preorder(NodeList,root);
     return NodeList;
    }
};
