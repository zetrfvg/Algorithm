/*
多源BFS
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]) continue;
                if(dis[xx][yy]) continue;
                ans=max(ans,dis[xx][yy]=dis[x][y]+1);
                q.push({xx,yy});
            }
        }
        return ans;
    }
};
