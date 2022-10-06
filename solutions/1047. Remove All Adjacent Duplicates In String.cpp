class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push('#');
        for(int i =0;i<s.size();i++){
            if(st.top() == s[i]){
                st.pop();
            }
            else st.push(s[i]);
        }
        int i =0;
        while(st.size()){
            if(st.top() != '#'){
              s[i] = st.top();
               i++;
            }
            st.pop();   
        }
        s.resize(i);
        reverse(s.begin(),s.end());
        return s;
    }
};
