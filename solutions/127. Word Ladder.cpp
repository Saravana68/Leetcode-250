// TIME : M * N^2 * 26 M -> size of wordList N-> size of beginWord another N -> comparing str with endWord inside queue
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        //if(st.count(endWord) == 0) return 0;
        vector<int>arr = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        if(st.count(endWord) == 0) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(q.size()){
            auto [str,count] = q.front(); q.pop();
            if(str == endWord) return count;
            
            for(int i = 0;i<str.size();i++){
                char ch = str[i];
                for(int j = 0;j<arr.size();j++){
                    //cout<<str<<" ";
                    str[i] = arr[j];
                    if(st.count(str) && str[i]!=ch) 
                        q.push({str,count+1});
                }
                str[i] = ch;
            }
            
            st.erase(str);
        }
        return 0;
    }
};
