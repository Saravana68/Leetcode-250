​
class Solution {
public:
    #define p pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> answer;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i =0;i<nums.size();i++){
            if(mp.count(nums[i])){
            pq.push({mp[nums[i]],nums[i]});
            mp.erase(nums[i]);
            }
            if(pq.size() > k) 
                pq.pop();
        }
        while(pq.size()){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};
