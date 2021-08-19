class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
       
        /* approach
         01.in given grid,vertical lines and horizontal lines form area inside lines and outside lines
         02.we need to find maximum area formed by lines both outside lines and inside are inclusive
         03. since outside area also covered we need to consider also for that insert size of row and col inside 
         horizontalCuts and verticalCuts
         04. we are getting largest length and breadth checking pair difference so to insert h and w in crct position
         we are sorting the horizontalCuts and verticalCuts array
         05. now find largest pair in lenght and breadth 
         06. return length*breadth using typecasting
         time: sorting O(nlogn) space: O(1)
        */
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
         int rowSize = horizontalCuts.size();
         int colSize = verticalCuts.size();
         int prevh =0,prevw=0;
         int length =0;
          int breadth =0;
        
         for(int i =0;i<rowSize;i++){
             length = max(length,horizontalCuts[i]-prevh);
             prevh = horizontalCuts[i];
           }
        
         for(int j =0;j<colSize;j++){
              breadth = max(breadth,verticalCuts[j]-prevw);
              prevw = verticalCuts[j];
         }
        
         return (int)((long)length*breadth%1000000007);
    
​
    }
};
