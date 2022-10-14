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
    TreeNode* solve(int &index , int min,int max,vector<int> &arr){
        if(index >= arr.size()) return NULL;
        TreeNode* root = NULL;
        if(min < arr[index] && arr[index] < max){
            root = new TreeNode(arr[index]);
            index++;
        if(index < arr.size()){
            root->left = solve(index,min,root->val,arr);
        }
        if(index < arr.size()){
            root->right = solve(index,root->val,max,arr);
        }
        }
      return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& arr) {
        if(!arr.size()) return NULL;
        int index = 0;
        return solve(index,INT_MIN,INT_MAX,arr);
    }
};
