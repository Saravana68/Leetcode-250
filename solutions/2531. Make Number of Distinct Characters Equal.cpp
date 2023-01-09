                if(mp1[x] == 0) mp1.erase(x);
                mp2[y]--;
                if(mp2[y] == 0) mp2.erase(y);
                
                mp1[y]++;
                mp2[x]++;
                if(mp1.size() == mp2.size()) return true;
                
                mp1[y]--;
                if(mp1[y] == 0) mp1.erase(y);
                mp2[x]--;
                if(mp2[x] == 0) mp2.erase(x);
                
                mp1[x]++;
                mp2[y]++;
            }
        }
        
        return false;
    }
};
*/
​
​
class Solution {
public:
    bool doCheck(vector<int> &dict1,vector<int> &dict2){
        int cnt1 = 0 , cnt2 = 0;
        for(int i =0;i<26;i++){
            if(dict1[i] > 0) cnt1++;
            if(dict2[i] > 0) cnt2++;
        }
        return cnt1 == cnt2;
    }
    bool isItPossible(string word1, string word2) {
        vector<int> dict1(26,0);
        vector<int> dict2(26,0);
        for(char x : word1) dict1[x - 'a']++;
        for(char x : word2) dict2[x - 'a']++;
        
        for(int i = 0;i<26;i++){
            if(dict1[i] == 0) continue;
            for(int j = 0;j<26;j++){
               if(dict2[j] > 0){
                   dict1[i]--;
                   dict2[j]--;
                   dict1[j]++;
                   dict2[i]++;
                   if(doCheck(dict1,dict2)) return true;
                   dict1[j]--;
                   dict2[i]--;
                   dict1[i]++;
                   dict2[j]++;
               } 
            }
        }
        return false;
    }
};
