/*
暴力搜索即可通过
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sx,sy,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]){
                    cnt++;
                }else if(grid[i][j]==1){
                    sx=i,sy=j;
                    cnt++;
                }
            }
        }
        function<int(int,int,int)> dfs=[&](int x,int y,int c){
            if(grid[x][y]==2){
                return c?0:1;
            }
            int res=0;
            grid[x][y]=-1;
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]==-1) continue;
                res+=dfs(xx,yy,c-1);
            }
            grid[x][y]=0;
            return res;
        };
        return dfs(sx,sy,cnt);
    }
};
