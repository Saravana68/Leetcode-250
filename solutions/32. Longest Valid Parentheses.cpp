class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return false;
        stack<int> st;
        st.push(-1);
        int res = 0;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(ch == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else {
                    res = max(res,i-st.top());
                }
            }
        }
        return res;
    }
};
