​
class Solution {
public:
    TreeNode* solve(int start, int end,unordered_map<int,int> &ListMap){
        if(start > end) return NULL;
        TreeNode* root = NULL;
        int mid = start + (end - start) / 2;
        if(ListMap.count(mid)){
            root = new TreeNode(ListMap[mid]);
            root->left = solve(start,mid-1,ListMap);
            root->right = solve(mid+1,end,ListMap);
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int,int> ListMap;
        ListNode* curr = head;
        int key = 0;
        while(curr){
            ListMap[key] = curr->val;
            curr = curr->next;
            key++;
        }
        return solve(0,key-1,ListMap);
    }
};
