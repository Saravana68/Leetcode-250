/*
TIME : O(NlogN) SPACE :O(N)
--------------- ----------
vector<vector<int>> merge(vector<vector<int>>& arr) {
        
        vector<vector<int>> answer;
        sort(arr.begin(),arr.end());
        vector<int> prev = {arr[0][0],arr[0][1]};
        
        for(int i = 1;i<arr.size();i++){
           if(arr[i][0] <= prev[1]){
               prev[0]= min(prev[0],arr[i][0]);
               prev[1] = max(prev[1],arr[i][1]);
           }
           else{
               answer.push_back(prev);
               prev[0] = arr[i][0];
               prev[1] = arr[i][1];
           }
        }
        answer.push_back(prev);
        return answer;
    }
*/
​
​
// O(1) SPACE SOLUTION 
​
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        
        int res = 0;
        for(int i =1;i<arr.size();i++){
            if(arr[i][0] <= arr[res][1]){
                arr[res][0] = min(arr[res][0],arr[i][0]);
                arr[res][1] = max(arr[res][1],arr[i][1]);
            }
            else{
                res++;
                arr[res][0] = arr[i][0];
                arr[res][1] = arr[i][1];
            }
        }
        arr.resize(res+1);
        return arr;
    }
};
