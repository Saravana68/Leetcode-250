class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int totalSum = 0;
        for(auto x : nums) totalSum += x;
        if(totalSum == goal) return 0;
        
        long long int required = abs(goal - totalSum);
        if(required <= limit) return 1;
        
        long long int ans = required / limit;
        if(required % limit != 0) ans++;
        
        return ans;
        
        
    }
};
