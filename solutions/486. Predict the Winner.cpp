class Solution {
public:
    int dp[20][20] = {{0}};
    long long func(int start,vector<int> arr,int end){
        if(end-start==1){
            return max(arr[start],arr[end]);
        }
        if(end==start)
            return arr[start];
        if(dp[start][end]!=0){
            return dp[start][end];
        }
        int temp1 = arr[start] + min(func(start+2,arr,end),func(start+1,arr,end-1));
        int temp2 = arr[end] + min(func(start,arr,end-2),func(start+1,arr,end-1));
        dp[start][end] = max(temp1,temp2);
        return dp[start][end];
    }
    bool PredictTheWinner(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum +=nums[i];
        }
        int player1 = func(0,nums,n-1);
        int player2 = sum - player1;
        return (player1>=player2);
    }
};
