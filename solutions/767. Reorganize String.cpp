class Solution {
public:
    string reorganizeString(string s) {
        int max = 0;
        char maxChar;
        unordered_map<char,int> mp;
        for(char x : s){
            mp[x]++;
            if(mp[x] > max){
                maxChar = x;
                max = mp[x];
            }
        }
    
        if(mp[maxChar] > (s.size()+1)/2) return "";
        int i = 0;
        while(mp[maxChar] > 0){
            s[i] = maxChar;
            i += 2;
            mp[maxChar]--;
        }
        
        mp.erase(maxChar);
        for(auto it : mp){
            char ch = it.first;
            int freq = it.second;
            while(freq >0){
                if(i  >= s.size()) i = 1;
                s[i] = ch;
                i += 2;
                freq--;
            } 
        }
        return s;
    }
};
