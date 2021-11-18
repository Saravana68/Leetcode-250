public:
    
  /*
    NAIVE APPROACH    ( 42/44  TESTCASES PASSED & TLE IN 43rd TESTCASE )
    ---------------
    static bool compare(vector<int> a, vector<int> b){
        return a.back() < b.back();
    }
    
    int maxEvents(vector<vector<int>>& events) {
        bool vis[100000] ={0};
        sort(events.begin(),events.end(),compare);
        int res =0;
       for(int i =0;i<events.size();i++){
            int l = events[i][0];
            int r = events[i][1];
               for(int k = l;k<=r;k++){
                 if(vis[k] == false){
                    res++;
                    vis[k] = true;
                     break;
               }
             }
           }
        return res;
       }
  */
    
    int maxEvents(vector<vector<int>>& events) {
        
       int n = events.size();
       sort(events.begin(),events.end());
       priority_queue<int,vector<int>,greater<int>> pq;
       
       int count = 0;
       int i =0;
        
       for(int d =1;d<=100000;d++){
           
           while(pq.size() && pq.top() <d)
               pq.pop();
           
           while(i<n && events[i][0] == d){
               pq.push(events[i][1]);
               i++;
           }
           
           if(pq.size()){
               pq.pop();
               count++;
           }
       }
        
        return count;
    }
};
