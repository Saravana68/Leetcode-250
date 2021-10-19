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
    int  preindx=0,postindx=0;
      TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         
          TreeNode *root = new TreeNode(preorder[preindx++]);
          if(root->val!=postorder[postindx]){
              root->left=constructFromPrePost(preorder,postorder);
          }
          if(root->val!=postorder[postindx]){
              root->right=constructFromPrePost(preorder,postorder);
          }
            postindx++;
          return root;
    }
};
