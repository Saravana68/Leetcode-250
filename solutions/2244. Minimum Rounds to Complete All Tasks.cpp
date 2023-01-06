class Solution {
public:
    
    // Brute Force approach - TLE |  75/79 testcases passed | O(N^2) TIME O(N) Space
    int doSolveMinRounds(vector<int> &arr){
        int answer = 0;
        int n = arr.size();
        vector<int> vis(n,0);
        for(int i =0;i<n;i++){
            if(vis[i]) continue;
            int freq = 0;
            for(int j = i;j<n;j++){
                if(arr[j] == arr[i]){
                    freq++;
                    vis[j] = 1;
                }
            }
            if(freq < 2) return -1;
            int twos = (freq / 2) + (freq % 2 != 0);
            int threes = (freq / 3) + (freq % 3 != 0);
            
            answer += min(twos, threes);
        }
        return answer;
        
    }
    // Efficient Approach - Accepted | O(N) TIME & O(N) space
    int doSolveMinrounds(vector<int> &arr){
        unordered_map<int,int> FreqMap;
        for(int x : arr)
             FreqMap[x]++;
        int answer = 0;
        for(int x : arr){
            if(FreqMap.count(x) == 0) continue;
            int freq = FreqMap[x];
            FreqMap.erase(x);
            if(freq < 2) return -1;
            int twos = (freq / 2) + (freq % 2 != 0);
            int threes = (freq / 3) + (freq % 3 != 0);
            answer += min(twos, threes);
        }
        return answer;
        }
    
    int minimumRounds(vector<int>& arr) {
        return doSolveMinrounds(arr);
    }
};
