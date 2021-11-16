class Solution {
public:
   
    
    int latestNonConflicting(vector<int>& startTime, vector<int>& endTime,vector<pair<int,int> > &jobs, int i ){
        for(int j=i-1; j>=0;j--){
         if(jobs[j].first<=startTime[jobs[i-1].second])
             return j;
        }
        return -1;
        
    }
    
    int find(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int n, vector<pair<int,int> > &jobs, int dp[] ){
        if(n==1){
            return profit[jobs[0].second];
        }
        if(dp[n]!=-1)
            return dp[n];
        
        int option1 = find(startTime, endTime, profit, n-1, jobs, dp);
        int option2=0;
        option2+= profit[jobs[n-1].second];
        int i = latestNonConflicting(startTime, endTime, jobs, n);
       
        if(i!=-1){
            option2+=find(startTime, endTime, profit, i+1, jobs,dp);
        }
        
        return dp[n] =max(option1,option2);  
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      int dp[50004];
        vector<pair<int,int> > jobs;
        for(int i=0;i<endTime.size();i++){
            jobs.push_back({endTime[i], i});
            
        }
       memset(dp,-1,sizeof(dp));
        sort(jobs.begin(), jobs.end());
        return find(startTime, endTime, profit, startTime.size(), jobs, dp);
        
        
    }
};
