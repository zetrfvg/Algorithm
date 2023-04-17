/*
状压+BFS
*/
class Solution {
public:
    int sx,sy,n,m,cnt=0;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int f[50][50][1<<8];
    int get(char ch){
        if(ch>='a'&&ch<='z') return ch-'a';
        else return ch-'A';
    }
    int shortestPathAllKeys(vector<string>& grid) {
        n=grid.size(),m=grid[0].size();
        memset(f,-1,sizeof f);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    grid[i][j]='.';
                    sx=i,sy=j;
                }
                if(grid[i][j]>='a'&&grid[i][j]<='z') cnt++;
            }
        }
        queue<tuple<int,int,int>> q;
        q.push({sx,sy,0});
        f[sx][sy][0]=0;
        while(!q.empty()){
            auto [x,y,msk]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=n||yy<0||yy>=m) continue;
                if(grid[xx][yy]=='.'){
                    if(f[xx][yy][msk]==-1){
                        f[xx][yy][msk]=f[x][y][msk]+1;
                        q.push({xx,yy,msk});
                    }
                }else if(grid[xx][yy]>='a'&&grid[xx][yy]<='z'){
                    int key=(1<<get(grid[xx][yy]));
                    if(f[xx][yy][key|msk]==-1){
                        f[xx][yy][key|msk]=f[x][y][msk]+1;
                        if((key|msk)==((1<<cnt)-1)) return f[xx][yy][key|msk];
                        q.push({xx,yy,key|msk});
                    }
                }else if(grid[xx][yy]>='A'&&grid[xx][yy]<='Z'){
                    int lock=(1<<get(grid[xx][yy]));
                    if(msk&lock){
                        if(f[xx][yy][msk]==-1){
                            f[xx][yy][msk]=f[x][y][msk]+1;
                            q.push({xx,yy,msk});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
