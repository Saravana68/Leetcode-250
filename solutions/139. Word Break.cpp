class Solution {
public:
    bool f(string s,int i , unordered_set<string> &dict,vector<int> &dp){
        if(i == s.size())
            return true;
        if(dp[i] != -1 ) return dp[i];
        string temp ="";
        
        for(int idx = i;idx<s.size();idx++){
            temp.push_back(s[idx]);
            //cout<<temp<<endl;
            if(dict.count(temp) && f(s,idx+1,dict,dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> dp(s.size(),-1);
        for(auto str : wordDict)
            dict.insert(str);
        
        return f(s,0,dict,dp);
    }
};
