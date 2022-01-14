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
    int sum =0;
    void dfs(TreeNode* root,string & answer){
        if(!root)
            return;
        answer += to_string(root->val);
        cout<<answer<<" ";
        if(!root->left && !root->right){
            int number = stoi(answer,0,2);
            cout<<number<<endl;
            sum+= number;
            return;
        }
        dfs(root->left,answer);
        if(root->left)answer.pop_back();
        dfs(root->right,answer);
        if(root->right) answer.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        
        if(!root)
            return 0;
        string answer;
