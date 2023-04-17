/*
先预处理一个岛，把这个岛中的坐标都放入一个队列
对这个岛整体BFS，找到另一个岛的最近的1即可
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int n,m;
    queue<pair<int,int>> q,nq;
    void bfs(int a,int b,vector<vector<int>>& grid){
        q.push({a,b});
        grid[a][b]=2;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            int c=0;
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]!=1) continue;
                c++;
                q.push({xx,yy});
                grid[xx][yy]=2;
            }
            if(c<4) nq.push({x,y});
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    bfs(i,j,grid);
                    break;
                }
            }
            if(nq.size()) break;
        }
        int ans=0;
        while(!nq.empty()){
            int sz=nq.size();
            while(sz--){
                auto [x,y]=nq.front();
                nq.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]==2) continue;
                    if(grid[xx][yy]==1) return ans;
                    nq.push({xx,yy});
                    grid[xx][yy]=2;
                }
            }
            ans++;
        }
        return ans;

    }
};
