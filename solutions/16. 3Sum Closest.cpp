class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      
        sort(nums.begin(),nums.end());
        int result = INT_MAX;
        int answer;
        
        for(int i =0;i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
          
            while(j<k){
                 // cout<<i<<j<<k<<endl;
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target -sum) < abs(result)){
                    result = target - sum;
                    answer = sum;
                }
                if(sum > target) k--;
                else j++;
            }
        }
        return answer;
         
    }
};
