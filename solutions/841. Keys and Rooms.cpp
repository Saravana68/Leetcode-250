class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
        int visited_rooms =0;
        int n = rooms.size();
        vector<bool>visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        visited_rooms++;
        
        while(q.size()){
            
            int u = q.front();
            q.pop();
            for(auto v: rooms[u]){
                if(visited[v] == false){
                    q.push(v);
                    visited[v] = true;
                    visited_rooms++;
                }
            }
        }
        if(visited_rooms == n)
            return true;
        else 
            return false;
        
        
    }
};
