class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> a(n, vector<int>(n));
        
        int x, y, i; 
        int p = 0;    // to start from each (i,i) position in each iteration
        int N = n;
        int c = 1;    // counter for next number
        
        while(N>0) {
            
            x = p;
            y = p;
            
            if (N==1) {     // only 1 elem remaining
                a[x][y] = c++;
            } else {
                for(i=p; i<n-p-1; i++) {
                    a[x][y++] = c++;
                }
​
                for(i=p; i<n-p-1; i++)
                    a[x++][y] = c++;
​
                for(i=p; i<n-p-1; i++)
                    a[x][y--] = c++;
​
                for(i=p; i<n-p-1; i++)
                    a[x--][y] = c++;
            }
            
            N = N-2;
            p++;
        }
        
        return a;
    }
};
