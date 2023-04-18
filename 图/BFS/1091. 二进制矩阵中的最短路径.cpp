/*
简单BFS
把走过的路径置1，来避免重复走相同的点
*/
class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1) return -1;
        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        while(!q.empty()){
            auto [x,y,d]=q.front();
            q.pop();
            if(x==n-1&&y==m-1) return d;
            for(int i=0;i<8;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]) continue;
                grid[xx][yy]=1;
                q.push({xx,yy,d+1});
            }
        }
        return -1;
    }
};
