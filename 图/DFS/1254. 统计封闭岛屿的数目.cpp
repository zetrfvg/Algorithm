/*
对所有连通块DFS，判断它是否到达边界即可
DFS同时，把访问过的格子置1，以免重复访问
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        function<bool(int,int)> dfs=[&](int x,int y){
            if(x<0||x>=n||y<0||y>=m) return true;
            if(grid[x][y]) return false;
            bool res=0;
            grid[x][y]=1;
            for(int i=0;i<4;i++){
                res|=dfs(x+dx[i],y+dy[i]);
            }
            return res;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]){
                    if(!dfs(i,j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
