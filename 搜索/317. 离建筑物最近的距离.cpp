/*
多源BFS，从所有房子向空地进行搜索，把房子到空地的距离累加上
用哈希表记录每个空地分别已经被哪些房子经过，和经过的房子的数量
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int shortestDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int p[n][m][n][m];
        memset(p,0,sizeof p);
        vector<int> d(n*m),c(n*m);
        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({0,i*m+j,i*m+j});
            }
        }
        int cnt=q.size();
        while(!q.empty()){
            auto &[dis,pos,from]=q.front();
            int x=pos/m,y=pos%m;
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]||p[xx][yy][from/m][from%m]) continue;
                p[xx][yy][from/m][from%m]=1;
                c[xx*m+yy]++;
                d[xx*m+yy]+=dis+1;
                q.push({dis+1,xx*m+yy,from});
                
            }
            q.pop();
        }
        int ans=1e9;
        for(int i=0;i<n*m;i++){
            if(!grid[i/m][i%m]&&c[i]==cnt) ans=min(ans,d[i]);
        }
        return ans==1e9?-1:ans;
    }
};
