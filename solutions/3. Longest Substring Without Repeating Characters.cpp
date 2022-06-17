class Solution {
public:
    int lengthOfLongestSubstring(string str){
        if(str.length() == 0 ) return 0;
        if(str.length() == 1) return 1;
        unordered_set<char>s;
        int left = 0;
        int res = 1;
        for(int right = 0;right < str.length();right++){
            if(s.find(str[right])!= s.end()){
                while(left < right && s.find(str[right])!= s.end()){
                    s.erase(str[left]);
                    left++;
                }
                
            }
            s.insert(str[right]);
            res = max(res,right-left+1);
        }
        return res;
    }
};
