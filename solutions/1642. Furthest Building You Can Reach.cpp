/*
​
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int totalBricksUsed = 0;
        priority_queue<int> bricksUsed;
        int reach = 0;
        for (; reach < n-1; reach++) {
            // If current height is higher, we don't have to use
            // bricks or ladder.
            if (heights[reach] >= heights[reach+1]) {
                continue;
            }
        
            // We have to use either brick or ladder.
            int diff = heights[reach+1] - heights[reach];
        
            if (totalBricksUsed + diff <= bricks) {
                // Prefer bricks because we can later change from 
                // bricks to ladder as we will see below.
                totalBricksUsed += diff;
                bricksUsed.push(diff);
            } else if (ladders > 0) {
                // If even bricks are insufficient, check ladders.
                if (!bricksUsed.empty() && bricksUsed.top() > diff) {   // Alert: Corner case ** 
                    totalBricksUsed = totalBricksUsed - bricksUsed.top() + diff;
                    bricksUsed.pop();
                    bricksUsed.push(diff); // Thanks to @amanda_86
                }
                ladders--;
            } else {
                // Unfortunately, it's not possible to go ahead any further.
                break;
            }
        }
        return reach; // This is the max we can go ahead.
    }
};
​
*/
​
​
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
