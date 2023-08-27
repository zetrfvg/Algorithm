/*
从起点进行一个BFS，同时从所有的淹没点进行一个多源BFS，每次BFS扩展，先扩展淹没的点，再扩展可以通行的点即可
*/
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        int n=land.size(),m=land[0].size();
        int sx,sy,ex,ey;
        queue<pair<int,int>> q,arr;
        vector<vector<int>> d(n,vector<int>(m,-1));
        unordered_map<int,vector<pair<int,int>>> p;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]=="*"){
                    q.push({i,j});
                }else if(land[i][j]=="S"){
                    sx=i,sy=j;
                }else if(land[i][j]=="D"){
                    ex=i,ey=j;
                }
            }
        }
        arr.push({sx,sy});
        d[sx][sy]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==".") p[abs(i-sx)+abs(i-sy)].push_back({i,j});
            }
        }
        int ans=1;
        while(!q.empty()||!arr.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||xx>=n||yy<0||yy>=m) continue;
                    if(land[xx][yy]=="S"||land[xx][yy]=="."){
                        land[xx][yy]="*";
                        q.push({xx,yy});
                    }
                }
            }
            sz=arr.size();
            while(sz--){
                auto [x,y]=arr.front();
                arr.pop();
                if(x==ex&&y==ey) return d[x][y];
                for(int i=0;i<4;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||xx>=n||yy<0||yy>=m) continue;
                    if(land[xx][yy]=="D"||land[xx][yy]=="."){
                        if(d[xx][yy]!=-1) continue;
                        d[xx][yy]=d[x][y]+1;
                        arr.push({xx,yy});
                    }
                }
            }
        }
        return -1;
    }
};
