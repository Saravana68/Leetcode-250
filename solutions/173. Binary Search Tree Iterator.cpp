class BSTIterator {
public:
    
// we need to store the inorder of given binary tree and pointer for next() & hasNext() 
    vector<int> v;
    int curr =0 ;
    
    BSTIterator(TreeNode* root) {
        formInorder(root,v);
    }
    
    void formInorder(TreeNode*root,vector<int> &v){
        if(!root) return;
        formInorder(root->left,v);
        v.push_back(root->val);
        formInorder(root->right,v);
    }
    
    int next() {
        return v[curr++];
    }
    
    bool hasNext() {
        return curr < v.size();
    }
};
​
​
