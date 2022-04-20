class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.rbegin(),deck.rend());
        vector<int> v;
        int pos=0;
        for(auto i:deck) {
          
            if(!v.empty()) {
                int num = v[pos];
                 cout<<num<<" ";
                 v.push_back(v[pos++]);}
                 
            v.push_back(i);
        }
        return {v.rbegin(),v.rend()-pos};
    }
};
