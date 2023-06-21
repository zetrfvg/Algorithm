/*
网格图上的简单搜索
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        int ex,ey;
        function<void(int,int)> dfs=[&](int x,int y){
            if(x<0||x>=n||y<0||y>=m||!land[x][y]) return;
            land[x][y]=0;
            ex=max(ex,x),ey=max(ey,y);
            for(int i=0;i<4;i++){
                dfs(x+dx[i],y+dy[i]);
            }
        };
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]){
                    ex=0,ey=0;
                    dfs(i,j);
                    ans.push_back({i,j,ex,ey});
                }
            }
        }
        return ans;
    }
};
