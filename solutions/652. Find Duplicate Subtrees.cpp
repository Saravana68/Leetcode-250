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
    string solve(TreeNode* root, unordered_map<string,int> &mp, vector<TreeNode*> &ans){
        if(!root) return " ";
        
        string left = solve(root->left,mp,ans);
        string right = solve(root->right,mp,ans);
        string curr = "#" + left  + to_string(root->val)+ right +"#";
        cout<<root->val<<"curr: "<<curr<<endl;
        if(mp[curr] != -1) mp[curr]++;
        if(mp[curr] > 1){
            
            cout<<"Duplicate: "<<curr<<endl;
            ans.push_back(root);
            mp[curr] = -1;
        }
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans ={};
        unordered_map<string,int> mp;
        solve(root,mp,ans);
        return ans;
    }
};
