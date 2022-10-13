/**
 // TIME : O(N) // SPACE : O(N)  13.10.2022
class Solution {
public:
    void solve(TreeNode*root,unordered_set<TreeNode*> &st,TreeNode* parent,int &cam){
        
        if(!root) return;
        solve(root->left,st,root,cam);
        solve(root->right,st,root,cam);
        
        // if only one node present then its parent is NULL & root is not yet covered
        bool flag1 = (parent == NULL) && (!st.count(root));
        
        // if any left or right node not covered then covering that via current root is must
        bool flag2 = (!st.count(root->left) || !st.count(root->right));
        
        // if any two conditions true in above statements add camera.
        if(flag1 || flag2){
            cam++;
            st.insert(root);
            st.insert(root->left);
            st.insert(root->right);
            st.insert(parent);
        }
        
    }
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> st;
        // we dont want camera on leaf nodes thats why adding NULL in unordered_set
        st.insert(NULL);
        int cam = 0;
        solve(root,st,NULL,cam);
        return cam;
    }
};
 */
class Solution {
public:
    int dfs(TreeNode* root, int &cam){
        if(!root) return 1;
