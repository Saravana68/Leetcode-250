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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> answer;
        if(!root) return answer;
        
        queue<TreeNode*> q ;
        q.push(root);
        
        while(q.size()){
            vector<int> temp;
            int count = q.size();
            for(int i =0;i<count;i++){
                TreeNode * curr = q.front(); 
                q.pop();
                temp.push_back(curr->val);
                cout<<curr->val<<" ";
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            cout<<endl;
            answer.push_back(temp);  
        }
        return answer;
        
    }
};
