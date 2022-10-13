​
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
      bool isLastNode = false;
      queue<TreeNode*> q;
      q.push(root);
      while(q.size()){
          TreeNode* curr = q.front(); q.pop();
          if(curr == NULL) isLastNode = true;
          else{
              if(isLastNode) return false;
              q.push(curr->left);
              q.push(curr->right);
          }
      }
        return true;
    }
};
