class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
        
        int res = INT_MIN;
        int temp_prod = 1;
        for(auto x: nums)
        {
            if(x != 0){
                temp_prod *= x;
                res = max(res,temp_prod);
            }
            else if(x == 0)
                temp_prod = 1;    
        }
        return res;
        
    }
};
