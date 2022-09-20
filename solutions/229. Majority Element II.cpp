class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = nums[0];
        int num2 = nums[0];
        int cnt1 =0 , cnt2 = 0;
        vector<int> ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(num1 == nums[i]) cnt1++;
            else if(num2 == nums[i]) cnt2++;
            else if(cnt1 ==0){
                num1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                num2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i =0;i<n;i++){
            if(num1 == nums[i]) cnt1++;
            else if(num2 == nums[i]) cnt2++;
        }
        if(cnt1 > nums.size() /3) ans.push_back(num1);
        if(cnt2 > nums.size()/3) ans.push_back(num2);
        return ans;
    }
};
