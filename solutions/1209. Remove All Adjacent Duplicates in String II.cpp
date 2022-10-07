/* 07.10.2022 */  
​
class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>> st;
        string res= "";
        for(char ch : s){
            if(st.size() && st.top().first == ch){
                st.top().second++;
            }
            else st.push({ch,1});
                
            if(st.top().second == k) st.pop();
            }
            while(st.size()){
                int size = st.top().second;
                while(size--){
                    res.push_back(st.top().first);
                }
                st.pop();
            }
            reverse(res.begin(),res.end());
            return res;
        }
    
};
