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
        
        
      Solved after learning DP
      solution gives right correct similar to coins picking problem
      but memoization gives MLE - Memory limit exceeded
      but n can be 10e5 where creating that much greater array gives MLE.
      
      from both ends at max we need only k elements 
      so calculate sum from first k elem from left;
      reduce one by one from left starting from k-1 index upto index 0
      and add value from right from index n-1
      only ptr1 becomes -1 that means all elements removed from left side so stop loop.
     */
        
        int sum = 0;
        int n = arr.size();
        for(int i =0;i<k;i++)
            sum += arr[i];
        int ptr1 = k-1;
        int ptr2 = n-1;
        
        int result = sum;
        cout<<sum<<endl;
        while(ptr1> -1){
            sum = sum - arr[ptr1];
            sum = sum + arr[ptr2];
            cout<<sum<<" ";
            result = max(result,sum);
            ptr1--;
            ptr2--;
        }
        return result;
    }
};
