/*
对所有连通块DFS，统计这个连通块中格子的个数，以及它是否和边界接壤
DFS同时，把访问过的格子置0，以免重复访问
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0,cnt;
        function<bool(int,int)> dfs=[&](int x,int y){
            if(x<0||x>=n||y<0||y>=m) return true;
            if(!grid[x][y]) return false;
            cnt++;
            bool res=false;
            grid[x][y]=0;
            for(int i=0;i<4;i++){
                res|=dfs(x+dx[i],y+dy[i]);
            }
            return res;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    cnt=0;
                    if(!dfs(i,j)){
                        ans+=cnt;
                    }
                }
            }
        }
        return ans;
    }
};
