class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
             return 0;
        
        int count =0;
        stack<int> st;
        st.push(-1);
        for(int i =0;i<s.length();i++){
            
            if(s[i] =='(') st.push(i);
            else if(s[i] == ')'){
                
                st.pop();
                if(!st.empty()){
                    count = max(count,i - st.top());
                }
                else {
                    st.push(i);
                }
            }
        }
        return count;
    }
};
