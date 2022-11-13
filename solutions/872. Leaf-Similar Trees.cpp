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
    void Dfs(TreeNode* root, vector<int> &arr){
        if(!root) return;
        if(!root->left && !root->right) arr.push_back(root->val);
        Dfs(root->left,arr);
        Dfs(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nodeListone, nodeListtwo;
        Dfs(root1,nodeListone);
        Dfs(root2,nodeListtwo);
        
        if(nodeListone.size() != nodeListtwo.size()) return false;
        for(int i =0;i<nodeListone.size();i++){
            if(nodeListone[i] != nodeListtwo[i]) return false;
        }
        return true;
    }
};
