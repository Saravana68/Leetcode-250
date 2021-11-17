class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        
      sort(piles.begin(),piles.end());
      int n = piles.size();
      int idx = n-2;
      n = n/3;
      cout<<n<<endl;
​
        int res =0;
      while(n--){
          
          res += piles[idx];
          idx = idx-2;
          cout<<idx<<" ";
      }
     
     return res;   
        }
};
