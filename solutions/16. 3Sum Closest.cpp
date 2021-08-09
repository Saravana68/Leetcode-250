class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
    /*
       Brute force appraoch: 
       01. generating all possible triplets using three loops 
       and calculating their sum. 
       02. take abs( target - sum) if it is less than result = INT_MAX then
       update result and store the sum in seperate answer variable
       03. coming out of loop return answer variable
    */
        
    /* optimal approach:
        01. sort tha array and use two pointer technique to traverse the array
        02. apply above technique used in brute force approach
        03. after updating and storing value in answer variable 
        if sum > target do k-- else do j++
        04. return answer variable
        Time: O(N^2 + Nlogn ) space: O(n) for sorting
    */
        
        int n = nums.size();
        int result = INT_MAX;   
        sort(nums.begin(), nums.end());
        int answer;
        
        for(int i = 0; i< n-2;i++)
        {
            int j = i+1, k= n-1;
            while(j<k)
              {
                int sum = nums[j] + nums[k] + nums[i];
                if(abs(target - sum) < abs(result)){
                    result = target-sum;
                    answer = sum;
                }
                else if(sum > target ) k--;
                else j++;
               }
        }
        cout<<result;
        return answer;
        
        // First time solving : 09.08.2021
        
        
    }
};
