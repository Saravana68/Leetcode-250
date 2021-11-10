class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<int>q;// to record which buildings are still continuing and what is the max height among them
        vector<pair<int,pair<int,int>>>v;//v[0]={x,{h,0/1}} 0-> for start of a building and 1 for end
        for(int i=0;i<buildings.size();i++)
        {
            v.push_back({buildings[i][0],{buildings[i][2],0}});
            v.push_back({buildings[i][1],{buildings[i][2],1}});
        }
        sort(v.begin(),v.end());
        int last=0;
        vector<vector<int>>ans;
        unordered_map<int,int>m;
        for(int i=0;i<v.size();i++)
        {
            int a=v[i].first,b=v[i].second.first,c=v[i].second.second;
            
            if(c==0)//if a new building comes in
            {
                q.push(b);
                int z=q.top();
                if(z!=last)// if last point was at same height we dont add a new point with same height after that
                {
                    last=z;
                    ans.push_back({a,last});
                }
            }
            else// if a building ends
            {
