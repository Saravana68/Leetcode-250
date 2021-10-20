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
    int widthOfBinaryTree(TreeNode* root) {
​
        if(!root) return 0;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        int res = 1;
        while(q.size())
        {
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            res = max( res,end-start+1);
            for(int i = 0;i<count;i++)
            {
                auto p = q.front(); q.pop();
                int ind = p.second-start;
                if(p.first->left) q.push({p.first->left,2*ind+1});
                if(p.first->right) q.push({p.first->right,2*ind+2});
            }
        }
        return res;
    }
};
