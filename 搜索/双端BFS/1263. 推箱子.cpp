/*
用d[sx][sy][bx][by]来记录人在(sx,sy)、箱子在(bx,by)位置上推动的最小次数
搜索到的下一步如果没有推动箱子，则把下一个状态加入队头；
如果推动了箱子，则把状态加入队尾
*/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int minPushBox(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int d[21][21][21][21];
        memset(d,-1,sizeof d);
        int sx,sy,tx,ty,bx,by;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='S'){
                    sx=i,sy=j;
                }else if(grid[i][j]=='T'){
                    tx=i,ty=j;
                }else if(grid[i][j]=='B'){
                    bx=i,by=j;
                }
            }
        }
        deque<tuple<int,int,int,int>> q;
        q.push_back({sx,sy,bx,by});
        d[sx][sy][bx][by]=0;
        while(!q.empty()){
            auto [sx,sy,bx,by]=q.front();
            q.pop_front();
            if(bx==tx&&by==ty) return d[sx][sy][bx][by];
            for(int i=0;i<4;i++){
                int sxx=sx+dx[i],syy=sy+dy[i];
                if(sxx<0||sxx>=n||syy<0||syy>=m||grid[sxx][syy]=='#') continue;
                if(sxx==bx&&syy==by){
                    int bxx=bx+dx[i],byy=by+dy[i];
                    if(bxx<0||bxx>=n||byy<0||byy>=m||grid[bxx][byy]=='#') continue;
                    if(d[sxx][syy][bxx][byy]!=-1) continue;
                    d[sxx][syy][bxx][byy]=d[sx][sy][bx][by]+1;
                    q.push_back({sxx,syy,bxx,byy});
                }else{
                    if(d[sxx][syy][bx][by]!=-1) continue;
                    d[sxx][syy][bx][by]=d[sx][sy][bx][by];
                    q.push_front({sxx,syy,bx,by});
                }
            }
        }
        return -1;
    }
};
