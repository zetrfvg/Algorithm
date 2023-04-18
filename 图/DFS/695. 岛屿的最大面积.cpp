/*
DFS统计每个连通块的大小即可
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        function<int(int,int)> dfs=[&](int x,int y){
            if(x<0||x>=n||y<0||y>=m||!grid[x][y]) return 0;
            grid[x][y]=0;
            int res=1;
            for(int i=0;i<4;i++){
                res+=dfs(x+dx[i],y+dy[i]);
            }
            return res;
        };
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans=max(ans,dfs(i,j));
                }
            }
        }
        return ans;
    }
};
