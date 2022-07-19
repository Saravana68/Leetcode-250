class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string arr) {
        int start = 0;
        int ans = INT_MIN;
        char ansChar = arr[0];
        int n = arr.size();
        for(int i =0;i<n;i++){
            char ch = arr[i];
            int time = releaseTimes[i] - start;
            if(time == ans && ch > ansChar){
                ansChar = ch;
                ans = time;}
            else if (time > ans){
                ansChar = ch;
                ans = time;}
            start = releaseTimes[i];
        }
        return ansChar;
    }
};
