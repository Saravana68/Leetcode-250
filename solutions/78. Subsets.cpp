class Solution {
public:
    
  /* approach
    01. using bits
    for Ex: abc size = 3
    total subsets = pow(2,3) =8
    binary representation of numbers upto 8
    000 - NULL
    001 - c 
    010 - b
    100 - a
    110 - ab
    011 - bc
    101 - ac
    111 - abc
    create temp vector and store each subset and then push_back the temp vector to answer
    time: N*2^N space: O(N)
    */
    
  void insertSubset(int n,vector<int> & nums,vector< vector<int> > & answer)
  {
      int j =0;
      vector<int> temp;
      while(n>0)
      {
         int lastbit = n&1;
          if(lastbit)
              temp.push_back(nums[j]);
          j++;
          n = n>>1;
      }
      answer.push_back(temp);
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        if(n < 2){
           answer.push_back({});
            cout<<answer.size();
           answer.push_back({nums[0]});
        }
        else
        {
           for(int i =0;i<pow(2,n);i++)
           {
               insertSubset(i,nums,answer);
           }
        }
        return answer;
    }
};
