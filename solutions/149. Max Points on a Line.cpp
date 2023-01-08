​
class Solution {
public:
    double slope(double x1, double x2, double y1, double y2){
        return x1 == x2 ? INT_MAX : (y1 - y2) / (x1 - x2);
    }
    int maxPoints(vector<vector<int>>& p) {
        
        if(p.size() == 1) return 1;
        
        int ans = 0;
        for (int i = 0; i < p.size(); ++i){
            unordered_map<double,int> s;
            for (int y = i + 1; y < p.size(); ++y){
                double nextS = slope(p[i][0], p[y][0], p[i][1], p[y][1]);
                ans = max(ans, 1 + (++s[nextS]));
            }
        }
        return ans;
    }
};
