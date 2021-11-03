class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int sum = 0 ;
        priority_queue<int,vector<int>,greater<int> >  q;
        for(int i = 1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                q.push(heights[i]-heights[i-1]);
                if(q.size() > ladders){
                    sum += q.top();
                    q.pop();
                }
                if(sum > bricks)
                  return i-1;
            }
        }
        return heights.size()-1;
    }
};
