class Solution {
public:
    int strStr(string haystack, string needle) {
        
    /* brute force approach:
       01.traversing through every window of size m , whereas m = needle.size() .
       02. checking if windows matching with needle if yes return index of i-m
       03.if not found return -1
       Time: O(n-m+1 * m) space: O(1) for naive pattern searching algo
    */
     
    /* optimal:
       01. we can use KMP algorithm to find the pattern
       02. since it is a easy problem also only first occurence is asked I have 
       used string builtin find() function to search pattern
       Time: O(n) space: O(1);
    */
        
       if (haystack.empty() && needle.empty() ) 
            return 0;
        if(haystack.find(needle) != string::npos){
            int index = haystack.find(needle);
            return index;
        }
        else return -1;
        
        //first time solved: 10.10.2021
    }
};
