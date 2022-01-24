​
class Solution {
public:
    
   void getLevelOrderTraversal(TreeNode * root,vector<vector<int>> &answer){
       
       queue<TreeNode*> q;
       q.push(root);
       
       while(q.empty() == false){
           
          vector<int> temp;
          int n = q.size();
           
          for(int i =0;i<n;i++)
          { 
              
          TreeNode* curr = q.front(); q.pop();
          temp.push_back(curr->val);
          if(curr->left)
              q.push(curr->left);
          if(curr->right)
              q.push(curr->right);
          }
           answer.push_back(temp);
      }
   }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       if(!root) return {}; 
       vector<vector<int> > answer;
        
       getLevelOrderTraversal(root,answer);
       reverse(answer.begin(),answer.end());
       return answer;
        
    }
};
