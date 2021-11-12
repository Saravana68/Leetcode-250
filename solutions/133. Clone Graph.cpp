/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
​
class Solution {
public:
    
    void dfs(Node* curr){
        
        int n = curr->neighbors.size();
        for(int i =0;i<n;i++){
            Node* temp = curr->neighbors[i];
            
            if(mp.find(temp->val)!= mp.end()){
                curr->neighbors[i] = mp[temp->val];
            }
            else{
                curr->neighbors[i] = new Node(temp->val,temp->neighbors);
                mp[temp->val] = curr->neighbors[i];
                dfs(curr->neighbors[i]);
            }
        }
    }
    
    unordered_map<int,Node*> mp;
    Node* cloneGraph(Node* node) {
        
        if(!node) 
            return NULL;
        
        Node* root = new Node(node->val,node->neighbors);
        mp[root->val]   = root;
        dfs(root);
        
       return root;
    }
};
