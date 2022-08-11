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
