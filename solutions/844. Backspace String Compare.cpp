                if(s2.size()) s2.pop();
            }
        }
        while(s1.size() && s2.size()){
            char ch1,ch2;
            ch1 = s1.top(); s1.pop();
            ch2 = s2.top(); s2.pop();
            if(ch1 != ch2) return false;
        }
        if(s1.size() || s2.size()) return false;
        return true;
    }
};
*/
​
class Solution {
public:
    bool backspaceCompare(string s, string t) {
            int i = s.size()-1;
            int j = t.size()-1;
            
           while(i>=0 || j>=0){ 
            int count = 0;
              while(i>=0 && (count >0 || s[i] == '#')){
                if(s[i] == '#')
                    count++;
                else count--;
                i--;
                 }
            count = 0;
            while(j>=0 && (count >0 || t[j] == '#')){
                if(t[j] == '#') count++;
                else count--;
                j--;
            }
          if( i>=0 && j>=0){
               if(s[i] != t[j])
                   return false;
               else {
                   i--;
                   j--;
               }
           }
           else if(i>= 0 || j>=0)
                  return false;  
        }
       return true;
    }
};
​
​
