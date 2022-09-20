class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0 , cnt2 = 0;
        for(int i =0;i<nums.size();i++){
            if(num1 == nums[i]) cnt1++;
            else if(num2 == nums[i]) cnt2++;
            else if(cnt1 == 0){
                num1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 ==0){
                num2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cout<<cnt1<<cnt2<<endl;
        cout<<num1<<" "<<num2<<endl;
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(num1 == nums[i]) cnt1++;
            else if(num2 == nums[i]) cnt2++;
        }
        cout<<cnt1<<cnt2<<endl;
        if(cnt1 > nums.size()/3) answer.push_back(num1);
        if(cnt2 > nums.size()/3 ) answer.push_back(num2);
        return answer;
    }
};
