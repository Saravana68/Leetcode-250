class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i =0;i<s.size();i++){
            char x = s[i];
            if(x == '(')
                st.push(i);
            else if(x == ')'){
                if(st.empty() == true)
                    s[i] = '*';
                else 
                    st.pop();
            }
        }
        while(st.size()){
            int idx = st.top() ; st.pop();
            s[idx] = '*';
        }
        string answer; 
        for(int i =0;i<s.size();i++){
            if(s[i] != '*')
                answer.push_back(s[i]);
        }
        return answer;
    }
};
