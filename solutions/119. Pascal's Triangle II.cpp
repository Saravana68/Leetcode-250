class Solution {
public:
    vector<int> getRow(int rowIndex) {
    
    /* Brutefore approach: 
       01. forming pascal triange upto given row ,store it in separate 2d vector
       02. printing required row from that 2d vector
       time: O(n2)  space : O(n2)
    */
    
    /* optimal approach:
       01. dont need to create 2d vector and form all pascal triangle element
       02. we can do it using ncr for first index and then derive solution for next          index from that
       time: O(n)   space : O(n)
    */
     
        
      long long int res = 1;
      int row = rowIndex +1;
      int col = row;  // no of cols for each row is row size
      vector<int> answer;
      answer.push_back(1);
    
      for(int i =1; i< row;i++)
      {
          res = res*(row-i);
          res = res/i;
          answer.push_back(res);
      }
    return answer;
        
    }
};
