/*  
   BRUTEFORCE APPROACH   
   -------------------
   class Solution {
public:
    TreeNode* doConstructBST(vector<int> &preorder,int start,int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        int i;
        for( i= start+1; i<= end;i++){
            if(preorder[i]> root->val) break;
        }
        root->left = doConstructBST(preorder,start+1,i-1);
        root->right = doConstructBST(preorder,i,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return doConstructBST(preorder,0,preorder.size()-1);
    }
};
 */
class Solution {
public:
    int idx = 0;
    TreeNode* doConstructBST(vector<int> &preorder,int start, int end){
        if(idx >= preorder.size()) return NULL;
        TreeNode* root = NULL;
        if(preorder[idx] > start &&  preorder[idx] < end){
            root = new TreeNode(preorder[idx]);
            idx++;
            root->left = doConstructBST(preorder,start,root->val);
            root->right = doConstructBST(preorder,root->val,end);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        return doConstructBST(preorder,INT_MIN,INT_MAX);
    }
};
