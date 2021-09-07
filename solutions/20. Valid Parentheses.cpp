class Solution {
public:
    
    bool matching(char a , char b){
        return ( (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto x: s)
        {
            if(x == '(' || x== '{' || x == '[')
                st.push(x);
            else if(st.empty() == true)
                return false;
            else if(matching(st.top(),x) == false)
                 return false;
            else 
                st.pop();
        }
        return st.empty();
    }
};
