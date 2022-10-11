class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        int count = 0;
        
        for(int i = 0;i<arr.size();i++){
            int remainder = arr[i] % 60;
            int needed = 60 - remainder;
            needed = needed == 60 ? 0 : needed;
            if(mp.count(needed))
                count += mp[needed];
            
            mp[remainder]++;
        }
        return count;
    }
};
