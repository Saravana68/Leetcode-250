class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        map<int,deque<int>> mp;
        int d = 0;
        
        for(int i =0;i<matrix.size();i++){
            int temp = d;
            for(auto x : matrix[i]){
                if(temp % 2 == 0){
                    mp[temp].push_front(x);
                    temp++;
                }
                else {
                    mp[temp].push_back(x);
                    temp++;
                }
            }
            d++;
        }
        vector<int> ans;
        for(auto x : mp){
            deque<int> dq = x.second;
            while(dq.size()){
                ans.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};
