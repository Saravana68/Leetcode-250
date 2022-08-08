class Solution {
public:
    vector<string> ans;
     void f(int idx , string &s, unordered_set<string> &st,string temp){
         
         cout<<idx<<" "<<temp<<endl;
         if(idx == s.size()){
             temp.pop_back();
             ans.push_back(temp);
             return;
         }
         
         string initial = temp;
         string stream = "";
         for(int i = idx;i<s.size();i++){
             stream += s[i];
             if(st.count(stream)){
                 
                 temp += stream+" ";
                 //cout<<stream<<""<<temp<<endl;
                 f(i+1,s,st,temp);
                 temp = initial;
             }
         }
     }
    
    vector<string> wordBreak(string s, vector<string>& list) {
        unordered_set<string> st (list.begin(),list.end());
        string temp ="";
        f(0,s,st,temp);
        return ans;
        
    }
};
