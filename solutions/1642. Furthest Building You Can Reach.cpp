class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> gapQueue;
        int sum =0;
        for(int i = 1; i<arr.size();i++){
            if(arr[i] <= arr[i-1]) continue;
            int gap = arr[i] - arr[i-1];
            gapQueue.push(gap);
            if(gapQueue.size() > ladders){
                sum += gapQueue.top(); gapQueue.pop();
            }
            if(sum > bricks) return i -1;
        }
        return arr.size() -1 ;
    }
};
