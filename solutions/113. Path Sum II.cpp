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
    vector<vector<int>> answer;
    void solve(TreeNode* root, vector<int> &NodeList, int &target,int sum){
        if(!root) return;
        NodeList.push_back(root->val);
        sum += root->val;
        if(!root->left && !root->right){
            if(sum == target) answer.push_back(NodeList);
            return;
        }
        if(root->left){
            solve(root->left,NodeList,target,sum);
            NodeList.pop_back();
        }
        if(root->right){
            solve(root->right,NodeList,target,sum);
            NodeList.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> NodeList = {};
        solve(root,NodeList,targetSum,0);
        return answer;
    }
};
