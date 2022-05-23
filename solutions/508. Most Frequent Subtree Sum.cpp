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
    unordered_map<int,int> mp;
     unordered_set<int> sum;
    int maxFreq = 1;
    int solve(TreeNode* root){
      if(!root) 
          return 0;
       int left = solve(root->left);
       int right = solve(root->right);
       int currSum = root->val + left + right;
       sum.insert(currSum);
       mp[currSum]++;
       maxFreq = max(maxFreq,mp[currSum]);
       return currSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        solve(root);
        // cout<<"Freq: "<<maxFreq<<"sum[] size: "<<sum.size()<<endl;
        for(auto v : sum){
            cout<<v<<endl;
            if(mp[v] == maxFreq)
                ans.push_back(v);
