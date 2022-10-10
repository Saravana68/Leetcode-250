class Solution {
public:
 
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        deque<int> dq;
        int ans = INT_MAX;
        
        int i = 0;
        while(i < nums.size()){
            while(sum < target && i < nums.size()){
                sum += nums[i];
                dq.push_back(nums[i]);
                i++;
                cout<<i<<" ";
            }
            while(sum >= target && dq.size()){
                //cout<<ans;
                int size = dq.size();
                ans = min(ans,size);
                sum = sum - dq.front();
                dq.pop_front();
            }
        }
      
        return ans == INT_MAX ? 0 : ans;
    }
};
