class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int prevSmall[n],nextSmall[n];
        
        stack<int> s;
        
        s.push(0);
        for(int i =0;i<n;i++){
            
            while(!s.empty() && heights[s.top()]>= heights[i]){
                s.pop();
            }
            int temp = s.empty() ? 0 : s.top()+1;
            prevSmall[i] = temp;
            s.push(i);
        }
        while(s.size()) s.pop();
        
        s.push(n-1);
        for(int i = n-1;i>=0;i--){
            
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            int temp = s.empty()? n-1 : s.top()-1;
            // cout<<i<<" "<<temp<<endl;
            nextSmall[i] = temp;
            s.push(i);
        }
        int res = 0;
        for(int i =0;i<n;i++){
           int curr = (nextSmall[i] - prevSmall[i]+1)* heights[i];
            res = max(res,curr);
        }
        return res;
    }
};
