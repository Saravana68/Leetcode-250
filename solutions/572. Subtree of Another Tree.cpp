    // Preorder Traversal
    void preorder(TreeNode* root, string& str)
    {
        if(!root)
        {
            str += '$';
            return;
        }
        
        str += to_string(root->val);
        preorder(root->left,str);
        preorder(root->right,str);
    }
    
    // Function to check whether the subtree or not
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        // If subRoot is empty
        if(!subRoot)
            return true;
        
        // If root is empty and subRoot is non-empty
        if(!root)
            return false;
        
        // Create a string of inorder traversal of both the trees
        string inT, inS;
        inorder(root,inT);
        inorder(subRoot,inS);
        
        // If inS is not the substring of inT, return false
        if(inT.find(inS) == string::npos)
            return false;
        
        // If inS is the substring of inT
        // Create a string of preorder traversal of both the trees
        // Instead of preorder traversal, you can also take postorder traversal
        string preT, preS;
        preorder(root,preT);
        preorder(subRoot,preS);
        
        cout<<inT<<" "<<inS<<endl;
        cout<<preT<<" "<<preS<<endl;
        // If preS is the substring of preT, return true otherwise return false
        return (preT.find(preS) != string::npos);
    }
};
*/
string formString(TreeNode* root){
    if(!root)
         return " ";
    string left = formString(root->left);
    string right = formString(root->right);
    
    string temp = '*' + left + to_string(root->val) + right + '*';
    return temp;
}
class Solution {
