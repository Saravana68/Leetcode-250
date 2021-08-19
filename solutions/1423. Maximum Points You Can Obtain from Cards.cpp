class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     
    /*
     first time solved: 19.18.2021
     Goal: To find maximum sum by taking one card at a time from either side.
     Reduced Goal: To find maximum sum by taking x cards from front and k-x cards from back of      array.
    */
        
    /* approach 01:
       01. if we want to from k card then remaining cards will be n-k cards
       02. if sum of k cards have to maximum then sum of n-k cards should be minimum
       03. calculate total sum of the array
       04. find minimum sum of n-k array
       05. minus the minimum sum from total sum
       06. return that value
       Time: O(N-k) space: O(1)
       but it won't efficient if k = 10^5 and k =1
     */
        
     /* approach 02:
        01. find sum upto first K elements in original array from left side
        02. now remove one last left side element and add right side element
        03. do this until left has no elements
        04. update res = max(res,currSUm);
        05. return res
        Time: O(k) space:O(1)
     */
        
       
        vector<int>cp = cardPoints;
        int n = cp.size();
        int sum=0;
        
        for(int i=0;i<=k-1;i++)
            sum+=cp[i]; 
        int ans = sum;
        for(int i=k-1,j=n-1;i>=0;i--,j--){
            sum=sum-cp[i];
            sum=sum+cp[j];
            ans=max(ans, sum);
        }
        
        return ans;
    }
};
