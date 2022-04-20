class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k ==1)
             return 0;
        int product  =1;
        int ans = 0;
        deque<int> q;
        int start = 0;
        
        
        for(int end =0;end<nums.size();end++){
            
            product = product* nums[end];
            while(product >= k && q.size()){
                product = product / nums[q.back()];
                q.pop_back();
                start++;
            }
            q.push_front(end);
            if(product < k){
            ans += (end-start)+1;}
        }
        return ans;
    }
};
