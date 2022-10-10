class Solution {
public:
    int maxArea(vector<int>& height) {
    
    /* BruteForce :
       01. generate all area using two loops
       02. calculate area = (right - left) * min(left_value,right_value);
       03. update the result = max(resutl,area);
       04. return result
       Time: O(N2) space: O(1);
    */
        
    /* optimal :
       01. No need to generate all areas
       02. similar to two sum problem use two pointer approach
       03. caculate area and update result
       04. check for left_value and right_value
          a. if left_value is lesser do left++
          b. if right_value is lesser do right--
          c. if both are same either do left++ or right-- // left++ is better
       05. return result
       Time: O(N) space: O(1)
     */
    
        int n = height.size();
        int left = 0;
        int right = n-1;
        int result =0;
        
        while(left < right)
        {
            int left_height = height[left];
            int right_height = height[right];
            int area = (right - left )*min(left_height,right_height);
            result = max(result,area);
            
            if(left_height <=right_height ) left++;
            else  right --;
            
        }
        return result;
    //first time solved : 12.08.2021
    }
};
