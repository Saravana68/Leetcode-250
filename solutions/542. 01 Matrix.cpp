class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        for(int i =0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j] == 0)
                    q.push({i,j});
                else 
                    mat[i][j] = -1;
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            for(int k = 0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || y <0 || x>= mat.size() || y >=mat[0].size() || mat[x][y] != -1) continue;
                mat[x][y] = mat[i][j] + 1;
                q.push({x,y});
            }
        }
        return mat;
    }
};
