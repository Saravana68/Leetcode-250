class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    /* Bruteforce: 
      01. generate all possible profits using two loops 
      02. update maxProf as maximum profit among all profits
      03. return maxProf 
      time: O(n2) space: O(1);
    */
    
    /* optimal:
      since maxProf is obtained only when  lowest value is subtraction factor, so if we found element < current 
      minVal , no need to generate profits for  current Minval, just update Minval and calculate profits
      01. atmost one transaction is permitted, so largest element after index of smallest value will be the answer 
      02. this can be false if second minimum is appeared before overall minimum and its profit is greater than           Minimum element's profit. 
      03. run a loop from 0 to N
      04. update smallest value in each iteration
      05. update maximum profit in each iteration
      time: O(N) space: O(1)
     */
    
     // int maxProf = 0;
     // int minVal = INT_MAX;
     //  for(int i= 0 ; i< prices.size(); i++)
     //  {
     //      minVal = min(minVal,prices[i]);
     //      maxProf = max(maxProf,prices[i]-minVal);
     //  }
     // return maxProf;
        int mini = prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            int currProfit = prices[i] - mini;
            mini = min(prices[i],mini);
            maxProfit = max(maxProfit,currProfit);
        }
        return maxProfit;
    }
};
