class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
    
 /* Bruteforce approach:
   01. generate all pairs using two loops 
   02.check the pair sum % 60 == 0 
   03. if yes update it in result variable
   04.return result
 */
    
 /* optimal approach 01 :
    ~ if value is 150 we need 30 to be added so that it will be 180%60 == 0
    ~ 30 is nothing but 60 - (150%60)
    ~ we need to search 30 in map if found update result + =1
    ~ after that insert 30 in map also ,because when again another value requires 30 to get modulo it 
      can choose two 30's for that we need to update ( time[i]%60 ) after searching
      
     01.using above intuion apply it for all elemetns in array
     02.return result finally
     Time: O(N) space: O(N)
 */
​
  /* optimal approach 02 :
    01.same as previous method but instead of using unordered_map we can use array
    02.use array size of 60 and do the same above approach in that array
    03.here array of size 60 independent of input size
    04.whatever the input size , array[60] is constant
    Time: O(N) space: O(1)
 */
   
    int n = time.size();
    int freq[60]={0};
    int result =0;
    for(int i =0;i<n;i++)
    {
        int value = (60 - (time[i] % 60 ) == 60 )? 0: 60 - (time[i] % 60);
        
        result += freq[value];
        freq[time[i]%60] +=1;
    }
        
        return result;
    }
};
​
