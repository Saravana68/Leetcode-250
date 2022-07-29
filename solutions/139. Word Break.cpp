class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[s.size()] = true;
        int n = s.size();
        unordered_set<string> dict;
        for(auto str : wordDict)
            dict.insert(str);
        
        for(int i = n-1;i>=0;i--){
            string temp ="";
          for(int idx = i;idx<s.size();idx++){
            temp.push_back(s[idx]);
            if(dict.count(temp) && dp[idx+1]){
                 dp[i] = true;
                break;
            }
        }
        }
        return dp[0];
    }
};
