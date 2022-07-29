class Solution {
public:
    int minAddToMakeValid(string s) {
        int stack = 0;
        int invalidCount = 0;
        if(s.size() == 0 || s.size() ==1 ) return s.size();
        
        for(int i = 0; i < s.size();i++){
            char x = s[i];
            if(x== '(') stack++;
            else if(x == ')'){
                if(stack == 0)
                    invalidCount++;
                else stack--;
            }
        }
        return stack + invalidCount;
    }
};
