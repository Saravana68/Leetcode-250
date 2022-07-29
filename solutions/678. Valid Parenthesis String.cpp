class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open,star;
        for(int i =0;i<s.size();i++){
            if(s[i] == '(')
                open.push(i);
            else if(s[i] == '*')
                star.push(i);
            else{
                if(star.empty() && open.empty())
                    return false;
                if(open.size()) 
                    open.pop();
                else if(star.size()) star.pop();
            }
        }
        while(star.size() && open.size()){
            if(open.top() < star.top())
            {
                open.pop();
                star.pop();
            }
            else return false;
        }
        return open.size() == 0;
    }
};
