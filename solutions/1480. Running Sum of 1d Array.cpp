class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        int sum=0;
        vector<int>p;
        for(auto it = nums.begin(); it!= nums.end(); it++)
        {
            sum=sum+(*it);
            p.push_back(sum);
            
         }
        return p;
        
        //first time solved: 01.04.2021
    }
};
