class Solution {
    // to count total number of island
    int cnt=0;
    // used for the 4 directions(neighbours)
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        // base condition
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]=='0') return;
        // marks the sapce as water
        grid[i][j]='0';
        // call the dfs for all possible 4 directions
        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                // if land found start the dfs
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        // cnt will store the total numbers of islands
        return cnt;
    }
};
