class Solution {
public:
    int findParent(int i, vector<int> &parent){
        if(parent[i] == -1) return i;
        return parent[i] = findParent(parent[i],parent);
    }
    void doUnion(int u,int v, vector<int> &parent,vector<int> &rank){
        int uPar = findParent(u,parent);
        int vPar = findParent(v,parent);
        if(uPar == vPar) return;
        
        if(rank[uPar] < rank[vPar]){ parent[uPar] = vPar;}
        else if (rank[vPar] < rank[uPar]){ parent[vPar] = uPar; }
        else {
            parent[uPar] = vPar; rank[vPar]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        vector<int> parent(n),rank(n);
        for(int i =0;i<n;i++){
            parent[i] = -1;
            rank[i]= 0;
        }
        unordered_map<string,int> mailMap;
        for(int i =0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(mailMap.count(email) == 0){
                    mailMap[email] = i;
                }
                else {
                    doUnion(i,mailMap[email],parent,rank);
                }
            }
        }
        vector<string> mailList[n];
        for(auto it : mailMap){
            string mail = it.first;
            int node = findParent(it.second, parent);
            mailList[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i =0;i<n;i++){
            if(mailList[i].size() == 0) continue;
            sort(mailList[i].begin(),mailList[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string it : mailList[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};
