class Solution {
public:
    int minInsertions(string s) {
        string str;
        for(int i =0;i<s.size();i++){
            if(s[i] == '(')
                str.push_back(s[i]);
            else if(s[i]==')' && i<s.size()-1 && s[i+1] == ')'){
                str.push_back('}');
                i++;
            }
            else if(s[i]==')')
                str.push_back(s[i]);
        }
        cout<<str<<endl;
        int lbCount =0;
        int rbCount =0;
        for(auto x : str){
           if(x == '(')
               lbCount++;
            else{
                if(x == ')')
                    rbCount++;
                if(lbCount == 0)
                    rbCount++;
                else lbCount--;
            }
        }
        return rbCount + lbCount*2;
    }
};
