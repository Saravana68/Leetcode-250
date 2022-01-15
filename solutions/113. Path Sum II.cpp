class Solution {
public:
    vector<vector<int>> answer;
    void getPathsumNodes(TreeNode* root,vector<int>& temp,int sum,int targetSum,TreeNode* parent){
        
       if(!root)
           return;
        sum+= root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum == targetSum && parent!= NULL)
            answer.push_back(temp);
        
        if(root->left){
            getPathsumNodes(root->left,temp,sum,targetSum,root);
            temp.pop_back();
        }
        if(root->right){
            getPathsumNodes(root->right,temp,sum,targetSum,root);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
     if(!root)
         return answer;
     vector<int> temp;
     if(!root->left && !root->right && root->val == targetSum){
         
             temp.push_back(root->val);
             answer.push_back(temp);
         return answer;
         
     }  
        
