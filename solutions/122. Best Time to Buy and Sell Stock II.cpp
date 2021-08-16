class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      /* BruteForce:
        01. we can't sell the first value, because we didn't buy anything also we can't buy in last day 
        02.every element has three possiblities 
          a.buy it
          b.sell it
          c. skip it
        03. approach will be using recursion and time : 3^N ;
     */
     
     /* optimal: 
       01.valley - peak approach
       02.whenever a value found > previous value ,then we can buy that previous value and sell it in current value 
       03. like wise buy and sell whenever element greater than previous element found
       04. sum the obtained profits
       05. return sum
       time: O(n) space: O(1)
     */
        
      int profit = 0;
      for(int i = 1;i<prices.size();i++)
      {
          if(prices[i]>prices[i-1])
              profit += prices[i]-prices[i-1];
              
      }
        return profit;
    }
};
