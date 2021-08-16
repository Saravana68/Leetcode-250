class Solution {
public:
    int fib(int n) {
        
    //first time solved: 16.08.2021
    /* as of now I know only recursion not dp
     I solved it using recursion */
        if(n==0 || n == 1)
             return n;
        return fib(n-1) + fib(n-2);
    }
};
